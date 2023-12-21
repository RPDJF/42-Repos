/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/21 16:49:31 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

// DO NOT FORGET TO MAKE A BONUS LIB, OR PROECT ALLOCS

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

static void pipe_toggler(int *even_pipe, int *odd_pipe, int nth_child)
{
	if (nth_child % 2)
	{
		pipe(odd_pipe);
		dup2(even_pipe[0], STDIN_FILENO);
		close(even_pipe[0]);
		dup2(odd_pipe[1], STDOUT_FILENO);
		close(odd_pipe[1]);
	}
	else
	{
		pipe(even_pipe);
		dup2(odd_pipe[0], STDIN_FILENO);
		close(odd_pipe[0]);
		dup2(even_pipe[1], STDOUT_FILENO);
		close(even_pipe[1]);
	}
}

static void fd_toggler(t_pipex *pipex, int nth_child)
{
	if (nth_child <= 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		close(pipex->fd_in);
	}
	else if (nth_child >= pipex->nbcommands - 1)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		close(pipex->fd_out);
	}
}

static void	f_pipex(t_pipex *pipex)
{
	int		even_pipe[2];
	int		odd_pipe[2];
	int		nth_child;
	int		last_child;
	int		status;
	t_list	*childs;

	nth_child = 0;
	childs = 0;
	while(pipex->commands[nth_child])
	{
		pipe_toggler(even_pipe, odd_pipe, nth_child);
		fd_toggler(pipex, nth_child);
		last_child = child_init(pipex, nth_child);
		childs = ft_lstadd(childs, galloc(sizeof(int)));
		*((int *)ft_lstlast(childs)->content) = last_child;
		addgarbage(childs);
		nth_child++;
	}
	while(childs)
	{
		waitpid(*((int *)childs->content), &status, 0);
		childs = childs->next;
	}
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		exit (status);
	}
	cleargarbage();
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		exitcontextmsg(ERR_NOT_ENOUGH_ARGS, get_progname(argv));
	pipex = new_pipex(argc, argv, envp);
	f_pipex(pipex);
}
