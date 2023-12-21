/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:05:14 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/21 17:06:38 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"
#include <stdio.h>

pid_t	child_init(t_pipex *pipex, int nth_child)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		exitprogmsg(*pipex, strerror(errno));
	if (child == 0)
	{
		close(pipex->fd_out);
		if (access(pipex->commands[nth_child], R_OK & X_OK) < 0)
			progcontextmsg(*pipex, pipex->commands[nth_child], ERR_CMD_NOT_FOUND);
		execve(pipex->commands[nth_child], pipex->args[nth_child], pipex->envp);
		exit(127);
	}
	return (child);
}