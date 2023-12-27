/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/27 17:36:32 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

static char	*get_progname(char **argv)
{
	static char	*progname;

	if (!progname)
	{
		progname = ft_strrchr(argv[0], '/') + 1;
		if (!progname || !*progname)
			progname = argv[0];
	}
	return (progname);
}

static t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = galloc(sizeof(t_pipex));
	pipex->name = get_progname(argv);
	pipex->in = argv[1];
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		pipex->in = init_heredoc(argv[2], pipex);
		argv[1] = argv[0];
		argv[2] = HEREDOC_FILENAME;
		argv++;
		argc--;
	}
	pipex->fd_in = open(pipex->in, O_RDONLY);
	if (pipex->fd_in < 0)
		progcontextmsg(*pipex, pipex->in, strerror(errno));
	pipex->out = argv[argc - 1];
	pipex->fd_out = open(pipex->out, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (pipex->fd_out < 0)
		exitprogcontextmsg(*pipex, pipex->out, strerror(errno));
	pipex->envp = envp;
	pipex->nbcommands = 0;
	pipex->commands = fetch_commands(pipex, argc, argv);
	pipex->args = fetch_args(pipex, argv);
	return (pipex);
}

static int	wait_childs(t_list *childs)
{
	int	status;

	while (childs)
	{
		waitpid(*((int *)childs->content), &status, 0);
		childs = childs->next;
	}
	return (status);
}

static void	f_pipex(t_pipex *pipex)
{
	int		**comm;
	int		nth_child;
	int		last_child;
	int		status;
	t_list	*childs;

	nth_child = 0;
	childs = 0;
	comm = new_bidirectional_comm(pipex);
	while (pipex->commands[nth_child])
	{
		last_child = child_init(pipex, nth_child, comm);
		childs = ft_lstadd(childs, galloc(sizeof(int)));
		*((int *)ft_lstlast(childs)->content) = last_child;
		addgarbage(childs);
		nth_child++;
	}
	free_bidirectional_comm(comm, pipex);
	status = wait_childs(childs);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		exit (status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5 || (argc < 6 && !ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]))))
		exitcontextmsg(ERR_NOT_ENOUGH_ARGS, get_progname(argv));
	pipex = new_pipex(argc, argv, envp);
	f_pipex(pipex);
	exit (0);
}
