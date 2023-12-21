/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:05:14 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/21 15:07:31 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	first_command(t_pipex *pipex, int *pipes)
{
	close(pipex->fd_out);
	close(pipes[0]);
	if (pipex->fd_in < 0)
	{
		close(pipes[1]);
		exit (EXIT_FAILURE);
	}
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_in);
	dup2(pipes[1], STDOUT_FILENO);
	close(pipes[1]);
	if (access(*pipex->commands, R_OK & X_OK) < 0)
		progcontextmsg(*pipex, *pipex->commands, ERR_CMD_NOT_FOUND);
	execve(*pipex->commands, *pipex->args, pipex->envp);
	exit (127);
}

static void	second_command(t_pipex *pipex, int *pipes)
{
	close(pipex->fd_in);
	close(pipes[1]);
	dup2(pipes[0], STDIN_FILENO);
	close(pipes[0]);
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_out);
	if (access(pipex->commands[1], R_OK & X_OK) < 0)
		progcontextmsg(*pipex, pipex->commands[1], ERR_CMD_NOT_FOUND);
	execve(pipex->commands[1], pipex->args[1], pipex->envp);
	exit (127);
}

pid_t	first_child_init(t_pipex *pipex, int *pipes)
{
	pid_t	first_child;

	first_child = fork();
	if (first_child < 0)
		exitprogmsg(*pipex, ERR_FORK);
	if (first_child == 0)
		first_command(pipex, pipes);
	return (first_child);
}

pid_t	second_child_init(t_pipex *pipex, int *pipes)
{
	pid_t	second_child;

	second_child = fork();
	if (second_child < 0)
		exitprogmsg(*pipex, ERR_FORK);
	else if (second_child == 0)
		second_command(pipex, pipes);
	return (second_child);
}
