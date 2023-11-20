/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:34:10 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/20 15:27:18 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//	get path from envp stored in pipex struct
//	return splited paths env
//	secure exit on error
static char	**getpath(t_pipex *pipex)
{
	static char	**paths;
	int			i;

	if (!paths)
	{
		if (!pipex->envp)
			exitmsg(ERR_ALLOC);
		while (*pipex->envp && !ft_strnstr(*pipex->envp, "PATH=", 5))
			pipex->envp++;
		if (!*pipex->envp)
			exitmsg(ERR_ALLOC);
		paths = ft_split(*pipex->envp + 5, ':');
		if (!paths)
			exitmsg(ERR_ALLOC);
		i = 0;
		while (paths[i] && *paths[i])
		{
			if (paths[i][ft_strlen(paths[i]) - 2] != '/')
				paths[i] = ft_strjoin(paths[i], "/");
			if (!paths[i])
				exitmsg(ERR_ALLOC);
			i++;
		}
	}
	return (paths);
}

//	get command from char *command
//	returns full path command
//	secure exit on error
static char	*getcommand(t_pipex *pipex, char *command)
{
	char	*commandpath;
	int		i;

	if (command[0] == '/' || !getpath(pipex))
		return (command);
	i = 0;
	while (getpath(pipex)[i])
	{
		commandpath = ft_strjoin(getpath(pipex)[i], command);
		if (!commandpath)
			exitmsg(ERR_ALLOC);
		if (access(commandpath, R_OK & X_OK) >= 0)
			return (commandpath);
		gfree(commandpath);
		i++;
	}
	return (command);
}

char	**fetch_commands(t_pipex *pipex, int argc, char **argv)
{
	char	**commands;
	char	**command;
	int		i;

	i = 1;
	commands = (char **)ft_calloc(i, sizeof(char *));
	if (!commands)
		exitmsg(ERR_ALLOC);
	while (argv[i + 1] && i < argc - 1)
	{
		commands = ft_exallocf(commands, i * sizeof(char *),
				(i + 1) * sizeof(char *));
		if (!commands)
			exitmsg(ERR_ALLOC);
		command = ft_split(argv[i + 1], ' ');
		if (!command)
			exitmsg(ERR_ALLOC);
		commands[i - 1] = getcommand(pipex, command[0]);
		i++;
	}
	return (commands);
}
