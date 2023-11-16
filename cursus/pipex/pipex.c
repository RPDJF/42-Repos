/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/16 17:37:21 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	*name;

	name = ft_strrchr(argv[0], '/') + 1;
	if (!name || !*name)
		name = argv[0];
	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
	{
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		exitmsg(ERR_ALLOC);
	}
	pipex->name = name;
	pipex->in = argv[1];
	pipex->out = argv[argc - 1];
	pipex->envp = envp;
	pipex->commands = fetch_commands(pipex, argc, argv);
	if (!pipex->commands)
		exitmsg(ERR_ALLOC);
	return (pipex);
}

static void	f_pipex(t_pipex *pipex)
{
	pid_t	myfork;
	int		fd;

	myfork = fork();
	if (myfork < 0)
		exitmsg(ERR_FORK);
	fd = open(pipex->out, O_RDWR);
	if (fd < 0)
		exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
	if (dup2(fd, STDOUT_FILENO) < 0)
		exitprogmsg(*pipex, strerror(errno));
	if (close(fd) < 0)
		exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
	if (myfork == 0)
		execve(*pipex->commands,
			fetch_args(*pipex->commands, pipex->in), pipex->envp);
	else
		wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitmsg(ERR_NOT_ENOUGH_ARGUMENTS);
	pipex = new_pipex(argc, argv, envp);
	if (!pipex)
		exitmsg(ERR_ALLOC);
	check_files(*pipex);
	f_pipex(pipex);
	cleargarbage();
	exit(0);
}
