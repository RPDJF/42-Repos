/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/18 13:48:15 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

/*
*	Extend mem allocation to add the \0 char at the end
*/
char	*ft_memtostr(void *mem, size_t size)
{
	char	eos;

	eos = '\0';
	mem = ft_exallocf(mem, size, size + 1);
	if (!mem)
		return (0);
	((unsigned char *)mem)[size] = eos;
	return ((char *)mem);
}

#include <stdio.h>

size_t	fill_tab_with_nextline(void **tab, size_t size, int *fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	rbytes;

	rbytes = 1;
	while (rbytes > 0 && (!ft_memchr(*tab, '\n', size) || !*tab))
	{
		rbytes = read(*fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
			return (0);
		if (rbytes == 0)
			break ;
		if (ft_memchr(buffer, '\n', rbytes))
			rbytes = (char *)ft_memchr(buffer, '\n', rbytes) - buffer + 1;
		*tab = ft_exallocf(*tab, size, size + rbytes);
		size += rbytes;
		ft_memncat(*tab, size - rbytes, buffer, rbytes);
		if (!*tab)
			return (0);
	}
	return (size);
}

char	*get_next_line(int fd)
{
	char		*output;
	char		**p_output;
	size_t		tabsize;
	static int	s_fd;

	s_fd = fd;
	output = 0;
	p_output = &output;
	tabsize = 0;
	tabsize = fill_tab_with_nextline((void **)p_output, tabsize		, &s_fd);
	if (!tabsize)
	{
		free(output);
		return (0);
	}
	output = ft_memtostr(output, tabsize);
	if (!output)
		return (0);
	return (output);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
