/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:56:48 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/10 15:15:20 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**fetchcommands(char **args, int size)
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
		commands[size] = ft_strjoin("/bin/", tmp);
		if (!commands[size])
			return (0);
		gfree(tmp);
	}
	return (commands);
}

int	check_files(t_pipex pipex)
{
	char	*path;

	path = getfilepath(pipex.out);
	if (access(pipex.in, O_RDONLY) < 0
		|| access(path, O_RDWR) < 0)
		return (-1);
	gfree(path);
	return (0);
}

char	**loadargs(const char *src)
{
	char	**heap;
	int		fd;
	int		i;

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	heap = 0;
	while (i == 0 || heap[i - 1])
	{
		heap = ft_exallocf(heap, i * sizeof(char *), (i + 1) * sizeof(char *));
		if (!heap)
			secure_exit("Fail to allocate memory", 1);
		heap[i] = ft_get_next_line(fd);
		if (heap[i])
			if (heap[i][ft_strlen(heap[i]) - 1] == '\n')
				heap[i][ft_strlen(heap[i]) - 1] = 0;
		i++;
	}
	heap = ft_exallocf(heap, i * sizeof(char *), (i + 1) * sizeof(char *));
	if (!heap)
		secure_exit("Fail to allocate memory", 1);
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
	pipex = new_pipex(argc, argv);
	pipex->intake = loadargs(pipex->in);
	if (errno)
		secure_exit(strerror(errno), 1);
	execv(*(pipex->commands), strtabaddfront(pipex->intake, *(pipex->commands)));
	secure_exit(0, 0);
}
