/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:34:10 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/21 16:20:00 by rude-jes         ###   ########.fr       */
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
		while (*pipex->envp && !ft_strnstr(*pipex->envp, "PATH=", 5))
			pipex->envp++;
		paths = ft_split(*pipex->envp + 5, ':');
		i = 0;
		while (paths[i] && *paths[i])
		{
			if (paths[i][ft_strlen(paths[i]) - 2] != '/')
				paths[i] = ft_strjoin(paths[i], "/");
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
		if (access(commandpath, R_OK & X_OK) >= 0)
			return (commandpath);
		gfree(commandpath);
		i++;
	}
	progcontextmsg(*pipex, command, ERR_CMD_NOT_FOUND);
	commandpath = ft_calloc(1, sizeof(char));
	return (commandpath);
}

char	**fetch_commands(t_pipex *pipex, int argc, char **argv)
{
	char	**commands;
	char	**command;
	int		i;

	i = 1;
	commands = (char **)ft_calloc(i, sizeof(char *));
	while (argv[i + 1] && i < argc - 2)
	{
		commands = ft_exallocf(commands, i * sizeof(char *),
				(i + 1) * sizeof(char *));
		if (*argv[i + 1] && !ft_isspace(*argv[i + 1]))
		{
			command = ft_split(argv[i + 1], ' ');
			commands[i - 1] = getcommand(pipex, command[0]);
		}
		else
		{
			progcontextmsg(*pipex, argv[i + 1], ERR_CMD_NOT_FOUND);
			command = ft_calloc(2, sizeof(char *));
			commands[i - 1] = ft_calloc(1, sizeof(char));
		}
		i++;
	}
	return (commands);
}