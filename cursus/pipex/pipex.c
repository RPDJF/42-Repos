/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/21 15:37:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	*name;

	name = ft_strrchr(argv[0], '/') + 1;
	if (!name || !*name)
		name = argv[0];
	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
	{
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		exitmsg(ERR_ALLOC);
	}
	pipex->name = name;
	pipex->in = argv[1];
	pipex->fd_in = open(pipex->in, O_RDONLY);
	if (pipex->fd_in < 0)
		exitprogcontextmsg(*pipex, pipex->in, strerror(errno));
	pipex->out = argv[argc - 1];
	pipex->fd_out = open(pipex->out, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (pipex->fd_out < 0)
		exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
	pipex->envp = envp;
	pipex->commands = fetch_commands(pipex, argc, argv);
	pipex->args = fetch_args(pipex, argv);
	return (pipex);
}

static void	child_fork(t_pipex *pipex, int *pipes)
{
	close(pipes[0]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipes[1], STDOUT_FILENO);
	execve(*pipex->commands, *pipex->args, pipex->envp);
}

static void	parent_fork(t_pipex *pipex, int *pipes)
{
	close(pipes[1]);
	dup2(pipes[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	execve(pipex->commands[1], pipex->args[1], pipex->envp);
	return ;
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
		exit (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGS);
	pipex = new_pipex(argc, argv, envp);
	if (!pipex)
		exitmsg(ERR_ALLOC);
	check_files(*pipex);
	f_pipex(pipex);
}
