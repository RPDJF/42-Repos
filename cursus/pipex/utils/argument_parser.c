/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/21 16:21:29 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	***fetch_args(t_pipex *pipex, char **argv)
{
	char	***args;
	size_t	size;
	size_t	i;

	size = 0;
	while (pipex->commands[size])
		size++;
	args = (char ***)ft_calloc(size + 1, sizeof(t_pipex));
	i = 0;
	while (i < size)
	{
		args[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	return (args);
}
