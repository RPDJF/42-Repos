/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:05:14 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/27 17:47:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"
#include <stdio.h>

static void	fd_toggler(t_pipex *pipex, int nth_child)
{
	if (nth_child <= 0)
	{
		if (close(STDIN_FILENO) < 0
			|| (dup2(pipex->fd_in, STDIN_FILENO) < 0 && pipex->fd_in >= 0)
			|| (pipex->fd_in >= 0 && close(pipex->fd_in) < 0))
			exitprogmsg(*pipex, strerror(errno));
	}
	else if (nth_child >= pipex->nbcommands - 1)
	{
		if (close(STDOUT_FILENO) < 0
			|| (dup2(pipex->fd_out, STDOUT_FILENO) < 0 && pipex->fd_out >= 0)
			|| (pipex->fd_out >= 0 && close(pipex->fd_out) < 0))
			exitprogmsg(*pipex, strerror(errno));
	}
	if (nth_child == 1)
	{
		if (pipex->heredoc)
			if (unlink(HEREDOC_FILENAME) < 0)
				exitprogcontextmsg(*pipex, HEREDOC_FILENAME, strerror(errno));
	}
}

pid_t	child_init(t_pipex *pipex, int nth_child, int **comm)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		exitprogmsg(*pipex, strerror(errno));
	if (child == 0)
	{
		comm_toggler(comm, nth_child, pipex);
		fd_toggler(pipex, nth_child);
		if (access(pipex->commands[nth_child], R_OK & X_OK) < 0)
			progcontextmsg(*pipex,
				pipex->commands[nth_child], ERR_CMD_NOT_FOUND);
		execve(pipex->commands[nth_child], pipex->args[nth_child], pipex->envp);
		exit(127);
	}
	return (child);
}
