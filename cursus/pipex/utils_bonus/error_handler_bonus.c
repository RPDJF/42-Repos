/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:37:29 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/21 16:14:15 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	exitmsg(char *msg)
{
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	exitcontextmsg(char *msg, char *progname)
{
	ft_putstr_fd(progname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	exitprogmsg(t_pipex pipex, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	progcontextmsg(t_pipex pipex, char *context, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	ft_putstr_fd(context, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
}

void	exitprogcontextmsg(t_pipex pipex, char *context, char *msg)
{
	progcontextmsg(pipex, context, msg);
	cleargarbage();
	exit(1);
}
