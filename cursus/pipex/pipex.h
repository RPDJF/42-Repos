/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:31 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/23 14:29:02 by rude-jes         ###   ########.fr       */
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
	char		*name;
	char		*in;
	char		*out;
	int			fd_in;
	int			fd_out;
	char		**commands;
	int			nbcommands;
	char		***args;
	char		**envp;
}				t_pipex;

# define ERR_CMD_NOT_FOUND "command not found"
# define ERR_ALLOC "memory allocation failed"
# define ERR_FORK "an error occured during fork initialization"
# define ERR_NOT_ENOUGH_ARGS "missing or too much arguments for pipex"

// FROM FILE utils/argument_parser.c

//		fetch argument by adding commandname as index 0
char	***fetch_args(t_pipex *pipex, char **argv);

//	FROM FILE utils/command_parser.c

//		fetch command list for execv from argc argv
//		returns null terminated array of command paths
char	**fetch_commands(t_pipex *pipex, int argc, char **argv);

//	FROM FILE utils/error_handler.c

//		print error message in error output and exit 1
//		clear the garbage collector before exit
void	exitmsg(char *msg);
//		print error message in error output and exit 1
//		also prints program name
//		clear the garbage collector before exit
void	exitprogmsg(t_pipex pipex, char *msg);
//		print error message in error output
//		also prints program name
//		also prints context error
void	progcontextmsg(t_pipex pipex, char *context, char *msg);
//		print error message in error output and exit 1
//		also prints program name
//		also prints context error
//		clear the garbage collector before exit
void	exitprogcontextmsg(t_pipex pipex, char *context, char *msg);

//	FROM FILE utils/pathser.c

//		get the path of filename
//		returns the path
//		secure exit on error
char	*getfilepath(char *filename);

#endif