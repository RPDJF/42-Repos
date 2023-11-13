/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 20:16:27 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exitmsg(char *msg)
{
	if (msg && *msg)
		ft_putendl_fd(msg, 1);
	exit(1);
}

char	**getpath(t_pipex *pipex)
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

char	*getcommand(t_pipex *pipex, char *command)
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
		commands[i - 1] = getcommand(pipex, argv[i + 1]);
		i++;
	}
	return (commands);
}

t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
		exitmsg(ERR_ALLOC);
	pipex->in = argv[1];
	pipex->out = argv[argc - 1];
	pipex->envp = envp;
	pipex->commands = fetch_commands(pipex, argc, argv);
	if (!pipex->commands)
		exitmsg(ERR_ALLOC);
	return (pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGUMENTS);
	pipex = new_pipex(argc, argv, envp);
	if (!pipex)
		exitmsg(ERR_ALLOC);
	ft_printf("%s\n", *pipex->commands);
}
