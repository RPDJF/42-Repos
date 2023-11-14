/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/14 13:02:34 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	**tmp;

	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
		exitmsg(ERR_ALLOC);
	tmp = ft_split(argv[0], '/');
	if (!tmp)
		exitmsg(ERR_ALLOC);
	while(*tmp && *(tmp + 1))
		tmp++;
	pipex->name = *tmp;
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
	pid_t	myfork;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGUMENTS);
	pipex = new_pipex(argc, argv, envp);
	if (!pipex)
		exitmsg(ERR_ALLOC);
	check_files(*pipex);
	myfork = fork();
	if (myfork < 0)
		exitmsg(ERR_FORK);
	else if (myfork == 0)
		execve(*pipex->commands, fetch_args(*pipex->commands, argv[1]), envp);
	else
		wait(NULL);
	cleargarbage();
	exit(0);
}
