/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/14 12:33:50 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**fetch_args(char *command, char *argfile)
{
	char	**args;

	args = (char **)ft_calloc(3, sizeof(char *));
	if (!args)
		exitmsg(ERR_ALLOC);
	args[1] = argfile;
	args[0] = command;
	return (args);
}
