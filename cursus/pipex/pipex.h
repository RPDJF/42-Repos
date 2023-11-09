/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:00:48 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 14:00:48 by rude-jes         ###   ########.fr       */
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
}				t_pipex;

//	FROM utils/error_handler.c

//		send message before exiting program with int code
void	exitmsg(char *message, int code);
//		clean program before exiting with int code
void	secure_exit(char *msg, int code);

#endif