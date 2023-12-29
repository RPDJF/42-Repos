/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:45:31 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/29 14:37:51 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*getfilepath(char *fullpath)
{
	char	*filepath;

	fullpath = ft_strdup(fullpath);
	if (!fullpath)
		return (0);
	filepath = ft_strrchr(fullpath, '/');
	if (!filepath || !*filepath)
		filepath = ft_strdup("./");
	else
	{
		filepath++;
		*filepath = '\0';
		filepath = ft_strdup(fullpath);
	}
	if (!filepath)
		return (0);
	return (filepath);
}
