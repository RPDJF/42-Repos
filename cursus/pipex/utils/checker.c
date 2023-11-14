/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:42:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/14 15:05:34 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_files(t_pipex pipex)
{
	if (access(pipex.in, R_OK) < 0)
		exitprogcontextmsg(pipex, pipex.out, strerror(errno));
	if (access(pipex.out, W_OK) < 0)
		exitprogcontextmsg(pipex, pipex.out, strerror(errno));
}
