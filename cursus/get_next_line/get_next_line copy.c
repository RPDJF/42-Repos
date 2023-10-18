/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/18 19:15:00 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Returns a pointer to an extend malloc
* Copies bytes from ptr to the returned malloc
* ft_exallocf frees the ptr's pointed malloc
*
* Size inputs represents the size of the malloc in bytes
* If ptr is null, returns a new 'calloc' with newsize
* Returns 0 if allocation failed and free ptr
*/
#include <stdio.h>
void	*ft_exallocf(void *ptr, size_t size, size_t newsize)
{
	void	*p;
	void	*pwriter;

	p = malloc(newsize);
	if (!p)
	{
		free(ptr);
		return (0);
	}
	pwriter = p;
	if (!ptr)
	{
		while ((size_t)pwriter++ - (size_t)p < newsize)
			*((unsigned char *)(pwriter - 1)) = 0;
		return (p);
	}
	while ((size_t)pwriter - (size_t)p < size)
	{
		*((unsigned char *)(pwriter)) = *((unsigned char *)(ptr + (pwriter - p)));
		pwriter++;
	}
	while ((size_t)pwriter - (size_t)p < newsize)
		*((unsigned char *)(pwriter++)) = 0;
	free(ptr);
	return (p);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dstwriter;

	if (!dest && !src)
		return (0);
	dstwriter = dest;
	while (src++, dstwriter++, (size_t)dstwriter - 1 - (size_t)dest < n)
		*(dstwriter - 1) = *(unsigned char *)(src - 1);
	return (dest);
}

/*
*	Search for specific byte inside *s memory pointer
*	Return a pointer to the first occurence
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

/*
*	Concatenate src mem to dest mem
*	Dest needs to have enough space
*	Returns null if dest pointer is null
*/
void	*ft_memncat(void *dest, size_t start, void *src, size_t nb)
{
	int	i;

	if (!dest)
		return (0);
	i = 0;
	while ((unsigned int)i < nb)
	{
		((unsigned char *)dest)[start + i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

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


#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
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
ssize_t	fill_tab_with_lastbuffer(void **tab, ssize_t tabize, char *buffer, ssize_t buffersize)
{
	// need to do fill_tab_buffer_newline instead, wich will return next newline from buffer
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
	return (size + tabize);
}

/*
*	Fill tab pointer with the next line
*	Some buffersize don't work, need fix
*/
size_t	fill_tab_nextline(void **tab, ssize_t size, int *fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	rbytes;
	ssize_t			swap_rbytes;

	size = fill_tab_with_lastbuffer(tab, size, buffer, rbytes);
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
	tabsize = fill_tab_nextline((void **)p_output, tabsize, &s_fd);
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
