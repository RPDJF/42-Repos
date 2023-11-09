/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:56:48 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 13:56:48 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printgarbage(void)
{
	t_list	*garbage;

	garbage = *getgarbage();
	ft_putendl_fd("================", 1);
	while (garbage)
	{
		ft_printf("> %p\n", garbage->content);
		garbage = garbage->next;
	}
}

char	**fetchcommands(char **args, int size)
{
	char	**commands;

	commands = ft_calloc(size, sizeof(char *));
	if (!commands)
		return (0);
	while (size--)
	{
		commands[size] = ft_strdup(args[size]);
		if (!commands[size])
			return (0);
	}
	return (commands);
}

int	check_files(t_pipex pipex)
{
	if (access(pipex.in, O_RDONLY) < 0
		|| access(pipex.out, O_WRONLY) < 0)
		return (-1);
	return (0);
}

char	**loadfile(const char *src)
{
	char	**heap;
	int		fd;
	int		i;

	printgarbage();
	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (0);
	heap = ft_calloc(1, sizeof(char *));
	*heap = ft_get_next_line(fd);
	i = 0;
	while (heap[i++])
	{
		heap = ft_exallocf(heap, i * sizeof(char *), (i + 1) * sizeof(char *));
		heap[i] = ft_get_next_line(fd);
	}
	if (errno)
		secure_exit(strerror(errno), 1);
	return (heap);
}

t_pipex	*new_pipex(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
		secure_exit(0, 0);
	pipex->in = ft_strdup(argv[1]);
	pipex->out = ft_strdup(argv[argc - 1]);
	pipex->intake = 0;
	pipex->commands = fetchcommands(argv + 2, argc - 3);
	if (!pipex->in || !pipex->out || !pipex->commands)
		secure_exit("Fail to allocate memory", 1);
	if (check_files(*pipex) < 0)
		secure_exit(strerror(errno), 1);
	return (pipex);
}

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	if (argc < 5)
		secure_exit(0, 0);
	printgarbage();
	pipex = new_pipex(argc, argv);
	printgarbage();
	pipex->intake = loadfile(pipex->in);
	gfree(pipex->in);
	printgarbage();
	secure_exit(0, 0);
}
