/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/20 16:54:52 by rude-jes         ###   ########.fr       */
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
	pipex->args = fetch_args(pipex, argv);
	return (pipex);
}

static void	f_pipex(t_pipex *pipex)
{
	pid_t	childpid;
	int		outfile;
	int		pipes[2];
	int		infile;

	if (pipe(pipes) < 0)
		exitprogmsg(*pipex, strerror(errno));
	childpid = fork();
	if (childpid < 0)
		exitmsg(ERR_FORK);
	if (childpid == 0)
	{
		infile = open(pipex->in, O_RDONLY);
		if (infile < 0)
			exitprogcontextmsg(*pipex, pipex->in, strerror(errno));
		dup2(infile, STDIN_FILENO);
		dup2(pipes[0], STDOUT_FILENO);
		execve(*pipex->commands, *pipex->args, pipex->envp);
	}
	else
	{
		wait(0);
		outfile = open(pipex->out, O_WRONLY | O_CREAT | O_TRUNC, 00644);
		if (outfile < 0)
			exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
		dup2(pipes[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		execve(pipex->commands[1], pipex->args[1], pipex->envp);
	}
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
