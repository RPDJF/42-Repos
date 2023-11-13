/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:56:48 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 14:34:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		{
			if (heap[i][ft_strlen(heap[i]) - 1] == '\n')
			{
				heap[i][ft_strlen(heap[i]) - 1] = '"';
				heap[i] = ft_strjoin("\"", heap[i]);
			}
		}
		i++;
	}
	close(fd);
	heap = ft_exallocf(heap, i * sizeof(char *), (i + 1) * sizeof(char *));
	if (!heap)
		secure_exit("Fail to allocate memory", 1);
	return (heap);
}

t_pipex	*new_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = galloc(sizeof(t_pipex));
	if (!pipex)
		secure_exit(0, 0);
	pipex->in = ft_strdup(argv[1]);
	pipex->out = ft_strdup(argv[argc - 1]);
	pipex->intake = 0;
	pipex->commands = fetchcommands(argv + 2, argc - 3, envp);
	if (!pipex->in || !pipex->out || !pipex->commands)
		secure_exit("Fail to allocate memory", 1);
	if (check_files(*pipex) < 0)
		secure_exit(strerror(errno), 1);
	pipex->envp = envp;
	return (pipex);
}

void	start_pipex(t_pipex *pipex)
{
	char	**args;

	args = strtabaddfront(pipex->intake, *(pipex->commands));
	if (!args)
		secure_exit("Fail to allocate memory", 1);
	execve(*(pipex->commands), args, pipex->envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	**tmparg;

	if (argc < 5)
		secure_exit(0, 0);
	pipex = new_pipex(argc, argv, envp);
	//pipex->intake = loadargs(pipex->in);
	tmparg = (char **)ft_calloc(2, sizeof(char *));
	tmparg[0] = pipex->in;
	pipex->intake = tmparg;
	if (!pipex->intake)
		secure_exit("Fail to allocate memory", 1);
	start_pipex(pipex);
	secure_exit(0, 0);
}
