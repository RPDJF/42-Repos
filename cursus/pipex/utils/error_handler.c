/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:37:29 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/29 14:59:37 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exitmsg(char *msg)
{
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	exitcontextmsg(char *msg, char *progname)
{
	ft_putstr_fd(progname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (msg && *msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	exitprogmsg(t_pipex pipex, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	progcontextmsg(t_pipex pipex, char *context, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(context, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	exitprogcontextmsg(t_pipex pipex, char *context, char *msg)
{
	progcontextmsg(pipex, context, msg);
	cleargarbage();
	exit(1);
}
