/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/18 16:22:50 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <stdio.h>

/*
*	When get_next_line is called a second time, the
*	last buffer may contain unused bytes. This func
*	should be called in this case to fill tab with
*	unused bytes.
*
*	Returns tab size
*	Returns 0/NULL if tabsize is 0
*	Returns -1 if error
*/
ssize_t	fill_tab_with_lastbuffer(void **tab, char *buffer, ssize_t buffersize)
{
	ssize_t	size;
	ssize_t	usedbytes_size;

	if (!buffersize)
		return (0);
	usedbytes_size = (char *)ft_memchr(buffer, '\n', buffersize) - buffer + 1;
	if (buffersize == usedbytes_size)
		return (0);
	size = buffersize - usedbytes_size;
	*tab = malloc(size);
	if (!*tab)
		return (-1);
	ft_memncat(*tab, 0, buffer + usedbytes_size, size);
	return (size);
}

/*
*	Fill tab pointer with the next line
*	Some buffersize don't work, need fix
*/
size_t	fill_tab_with_nextline(void **tab, ssize_t size, int *fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	rbytes;
	ssize_t			swap_rbytes;

	size = fill_tab_with_lastbuffer(tab, buffer, rbytes);
	if (size == -1)
		return (0);
	rbytes = 1;
	while (rbytes > 0 && (!ft_memchr(*tab, '\n', size) || !*tab))
	{
		rbytes = read(*fd, buffer, BUFFER_SIZE);
		swap_rbytes = rbytes;
		if (rbytes < 0)
			return (0);
		if (rbytes == 0)
			break ;
		if (ft_memchr(buffer, '\n', rbytes))
			swap_rbytes = (char *)ft_memchr(buffer, '\n', rbytes) - buffer + 1;
		*tab = ft_exallocf(*tab, size, size + swap_rbytes);
		size += swap_rbytes;
		ft_memncat(*tab, size - swap_rbytes, buffer, swap_rbytes);
		if (!*tab)
			return (0);
	}
	return (size);
}

/*
*	Returns the next line from a file as a string, containing \n.
*	This functions use creates a static from fd, looping this
*	functions sends each newline from last one, until EOF char.
*/
char	*get_next_line(int fd)
{
	char		*output;
	char		**p_output;
	ssize_t		tabsize;
	static int	s_fd;

	s_fd = fd;
	output = 0;
	p_output = &output;
	tabsize = 0;
	tabsize = fill_tab_with_nextline((void **)p_output, tabsize, &s_fd);
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
	while (i++ < 15)
	{
		line = get_next_line(fd);
		printf("> %s\n", line);
		free(line);
	}
	return (0);
}
