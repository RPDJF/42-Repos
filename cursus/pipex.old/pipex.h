/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:00:48 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 13:37:54 by rude-jes         ###   ########.fr       */
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

//	FROM utils/checker.c

//		checkthat the needed files have necessarz permissions
int		check_files(t_pipex pipex);

//	FROM utils/command_handler.c

//		get PATH env variables splited by ':'
//		returned as char *[]
char	**getenvpath(char **envp);

//		get path to command in PATH env variable
//		check if read and execute rights are set
//		returns the path to the command
//		returns command if not found in PATH
char	*getcommand(char *command, char **envp);

//		returns all of the commands with their absolute path from PATH env var
char	**fetchcommands(char **args, int size, char **envp);

//	FROM utils/error_handler.c

//		send message before exiting program with int code
void	exitmsg(char *message, int code);
//		clean program before exiting with int code
void	secure_exit(char *msg, int code);

//	FROM utils/pipex_utils.c

//		extends char **tab by adding char *str at begin
char	**strtabaddfront(char **tab, char *str);
//		get the path of a specific file
char	*getfilepath(const char *file);

#endif