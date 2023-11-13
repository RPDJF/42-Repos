/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:49:25 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 14:11:07 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_files(t_pipex pipex)
{
	char	*path;

	path = getfilepath(pipex.out);
	if (access(pipex.in, R_OK) < 0
		|| access(path, W_OK) < 0)
		return (-1);
	gfree(path);
	return (0);
}
