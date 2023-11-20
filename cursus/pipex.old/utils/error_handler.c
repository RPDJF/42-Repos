/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:37:29 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/16 17:38:49 by rude-jes         ###   ########.fr       */
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

void	exitprogmsg(t_pipex pipex, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	cleargarbage();
	exit(1);
}

void	exitprogcontextmsg(t_pipex pipex, char *context, char *msg)
{
	ft_putstr_fd(pipex.name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(context, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	cleargarbage();
	exit(1);
}
