/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:31 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/14 16:55:45 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "betterft/betterft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	*name;
	char	*in;
	char	*out;
	char	**commands;
	char	**envp;
}				t_pipex;

# define ERR_NOT_ENOUGH_ARGUMENTS "pipex: not enough arguments"
# define ERR_ALLOC "pipex: fail to allocate memory"
# define ERR_COMMAND_NOT_FOUND "pipex: command not found: "
# define ERR_FORK "pipex: fail on fork"

// FROM FILE utils/argument_parser.c

//		fetch argument by adding commandname as index 0
char	**fetch_args(char *command, char *argfile);

// FROM FILE utils/checker.c

//		exit with error message if files permissions mismatch
void    check_files(t_pipex pipex);

//	FROM FILE utils/command_parser.c

//		fetch command list for execv from argc argv
//		returns null terminated array of command paths
char	**fetch_commands(t_pipex *pipex, int argc, char **argv);
//		print error message in error output and exit 1
void	exitmsg(char *msg);
//		print error message in error output and exit 1
//		also prints program name
void	exitprogmsg(t_pipex pipex, char *msg);
//		print error message in error output and exit 1
//		also prints program name
//		also prints context error
void	exitprogcontextmsg(t_pipex pipex, char *context, char *msg);

#endif