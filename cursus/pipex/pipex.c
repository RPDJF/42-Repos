/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/23 18:34:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = galloc(sizeof(t_pipex));
	pipex->name = ft_strrchr(argv[0], '/') + 1;
	if (!pipex->name || !*pipex->name)
		pipex->name = argv[0];
	pipex->in = argv[1];
	pipex->fd_in = open(pipex->in, O_RDONLY);
	if (pipex->fd_in < 0)
		progcontextmsg(*pipex, pipex->in, strerror(errno));
	pipex->out = argv[argc - 1];
	pipex->fd_out = open(pipex->out, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (pipex->fd_out < 0)
		exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
	pipex->envp = envp;
	pipex->nbcommands = 0;
	pipex->commands = fetch_commands(pipex, argc, argv);
	pipex->args = fetch_args(pipex, argv);
	return (pipex);
}

static void	child_fork(t_pipex *pipex, int *pipes)
{
	close(pipes[0]);
	if (pipex->fd_in < 0)
	{
		close(pipes[1]);
		exit (EXIT_FAILURE);
	}
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipes[1], STDOUT_FILENO);
	if (access(*pipex->commands, R_OK & X_OK) < 0)
		progcontextmsg(*pipex, *pipex->commands, ERR_CMD_NOT_FOUND);
	execve(*pipex->commands, *pipex->args, pipex->envp);
}

static void	parent_fork(t_pipex *pipex, int *pipes)
{
	close(pipes[1]);
	dup2(pipes[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	if (access(pipex->commands[1], R_OK & X_OK) < 0)
		progcontextmsg(*pipex, pipex->commands[1], ERR_CMD_NOT_FOUND);
	execve(pipex->commands[1], pipex->args[1], pipex->envp);
}

static void	f_pipex(t_pipex *pipex)
{
	pid_t	childpid;
	int		pipes[2];

	if (pipe(pipes) < 0)
		exitprogmsg(*pipex, strerror(errno));
	childpid = fork();
	if (childpid < 0)
		exitprogmsg(*pipex, ERR_FORK);
	if (childpid == 0)
		child_fork(pipex, pipes);
	else
	{
		wait(0);
		parent_fork(pipex, pipes);
		cleargarbage();
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGS);
	pipex = new_pipex(argc, argv, envp);
	f_pipex(pipex);
}
