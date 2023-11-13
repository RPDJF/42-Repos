/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:31 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 20:14:30 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "betterft/betterft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	char	*in;
	char	*out;
	char	**intake;
	char	**commands;
	char	**envp;
}				t_pipex;

# define ERR_NOT_ENOUGH_ARGUMENTS "pipex: not enough arguments"
# define ERR_ALLOC "pipex: fail to allocate memory"
# define ERR_COMMAND_NOT_FOUND "pipex: command not found: "

#endif