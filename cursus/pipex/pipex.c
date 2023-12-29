/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:21 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/29 14:57:56 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else
		status = 0;
	return (status);
}

static void	f_pipex(t_pipex *pipex)
{
	int		*pipes[2];
	int		nth_child;
	t_list	*childs;
	int		status;

	nth_child = 0;
	childs = 0;
	pipes[1] = 0;
	while (pipex->commands[nth_child])
	{
		pipes[0] = galloc(sizeof(int) * 2);
		pipe(pipes[0]);
		childs = ft_lstadd(childs, galloc(sizeof(pid_t)));
		*((pid_t *)ft_lstlast(childs)->content)
			= child_init(pipex, nth_child, pipes[0], pipes[1]);
		close(pipes[0][1]);
		if (pipes[1])
			close(pipes[1][0]);
		pipes[1] = pipes[0];
		nth_child++;
	}
	status = wait_childs(childs);
	close(pipes[0][0]);
	cleargarbage();
	exit (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc > 5)
		exitcontextmsg(ERR_TOO_MUCH_ARGS, get_progname(argv));
	else if (argc < 5)
		exitcontextmsg(ERR_NOT_ENOUGH_ARGS, get_progname(argv));
	pipex = new_pipex(argc, argv, envp);
	f_pipex(pipex);
}
