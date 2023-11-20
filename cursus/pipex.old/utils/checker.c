/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:42:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/16 18:13:25 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_files(t_pipex pipex)
{
	if (access(pipex.in, R_OK) < 0)
		exitprogcontextmsg(pipex, pipex.out, strerror(errno));
}
