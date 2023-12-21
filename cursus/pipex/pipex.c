/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/21 15:04:45 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

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

static void	f_pipex(t_pipex *pipex)
{
	pid_t	first_child;
	pid_t	second_child;
	int		pipes[2];
	int		status;

	if (pipe(pipes) < 0)
		exitprogmsg(*pipex, strerror(errno));
	first_child = first_child_init(pipex, pipes);
	second_child = second_child_init(pipex, pipes);
	if (second_child > 0)
	{
		close(pipes[0]);
		close(pipes[1]);
		if (first_child > 0)
			waitpid(first_child, 0, 0);
		waitpid(second_child, &status, 0);
		cleargarbage();
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			exit (status);
		}
	}
	cleargarbage();
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGS);
	pipex = new_pipex(argc, argv, envp);
	f_pipex(pipex);
}
