/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:05:14 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/29 14:29:06 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

//	Switch pipe communications using dup2 and close the useless ones
static void	sw_comm(t_pipex *pipex, int nth_child, int *pipes, int *old_pipes)
{
	close(pipes[0]);
	if (old_pipes)
	{
		dup2(old_pipes[0], STDIN_FILENO);
		close(old_pipes[0]);
	}
	else
		dup2(pipex->fd_in, STDIN_FILENO);
	if (nth_child >= pipex->nbcommands - 1)
		dup2(pipex->fd_out, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close(pipes[1]);
	close(pipex->fd_in);
	close(pipex->fd_out);
}

pid_t	child_init(t_pipex *pipex, int nth_child, int *pipes, int *old_pipes)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		exitprogmsg(*pipex, strerror(errno));
	if (child == 0)
	{
		sw_comm(pipex, nth_child, pipes, old_pipes);
		if (access(pipex->commands[nth_child], R_OK & X_OK) < 0)
			progcontextmsg(*pipex,
				pipex->commands[nth_child], ERR_CMD_NOT_FOUND);
		execve(pipex->commands[nth_child], pipex->args[nth_child], pipex->envp);
		exit(127);
	}
	return (child);
}
