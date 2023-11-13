/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 06:18:44 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 13:50:36 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**getenvpath(char **envp)
{
	static char	*path;

	if (!path)
	{
		while (*envp && !ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
			envp++;
		path = *envp + 5;
		if (!*path)
			return (0);
	}
	return (ft_split(path, ':'));
}

char	*getcommand(char *command, char **envp)
{
	char	**envpath;
	char	*path;
	int		i;

	envpath = getenvpath(envp);
	if (!envpath)
		return (0);
	i = 0;
	while (envpath[i])
	{
		path = ft_strdup(envpath[i]);
		if (!path)
			return (0);
		if (path[ft_strlen(path) - 1 != '/'])
			path = ft_strjoin(path, "/");
		if (!path)
			return (0);
		path = ft_strjoin(path, command);
		if (!path)
			return (0);
		if (access(path, R_OK) >= 0 && access(path, X_OK) >= 0)
			return (path);
		i++;
	}
	return (command);
}

char	**fetchcommands(char **args, int size, char **envp)
{
	char	**commands;
	char	*tmp;

	commands = ft_calloc(size, sizeof(char *));
	if (!commands)
		return (0);
	while (size--)
	{
		tmp = ft_strdup(args[size]);
		if (!tmp)
			return (0);
		commands[size] = getcommand(args[size], envp);
		if (!commands[size])
			return (0);
	}
	return (commands);
}
