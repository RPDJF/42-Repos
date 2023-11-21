/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:42:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/21 16:45:24 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_files(t_pipex pipex)
{
	if (access(pipex.in, R_OK) < 0)
		progcontextmsg(pipex, pipex.out, strerror(errno));
}
