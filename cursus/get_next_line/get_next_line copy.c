/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/19 14:25:37 by rude-jes         ###   ########.fr       */
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
void *ft_exallocf(void *ptr, size_t size, size_t newsize)
{
	void *p;
	void *pwriter;

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

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (dest > src)
		while (i < n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		while (i++ < n)
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
	return (dest);
}

/*
 *	Search for specific byte inside *s memory pointer
 *	Return a pointer to the first occurence
 */
void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

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
void *ft_memncat(void *dest, size_t start, void *src, size_t nb)
{
	int i;

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
char *ft_memtostr(void *mem, size_t size)
{
	char eos;

	eos = '\0';
	mem = ft_exallocf(mem, size, size + 1);
	if (!mem)
		return (0);
	((unsigned char *)mem)[size] = eos;
	return ((char *)mem);
}

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif

#include <stdio.h>

void *ft_submemf(void *s, size_t start, size_t len)
{
	void *p;

	p = malloc(len);
	if (!p)
		return (0);
	ft_memmove(p, s + start, len);
	return (p);
}

/*
*	trouver \n dans buffer
*	 si \n est prsent
*	 		aggrandir tab et concat buffer jusqu'à \n
*			décaler buffer avec memmove
*			changer valeur de bsize
*	 sinon
*			aggrandir tab et concat tout buffer
			bsize = 0
*	 Retourne la taille du nouveau tableau & met a jour la taille de bsize
*/
size_t fill_frombuffer(void **tab, ssize_t size, char *buff, ssize_t *bsize)
{
	size_t new_size;
	char *p_buff_nl;

	new_size = size;
	p_buff_nl = ft_memchr(buff, '\n', *bsize);
	if (p_buff_nl)
	{
		new_size += p_buff_nl - buff + 1;
		*tab = ft_exallocf(*tab, size, new_size);
		if (!*tab)
			return (0);
		ft_memncat(*tab, size, buff, new_size - size);
		if (buff == p_buff_nl)
			ft_memmove(buff, p_buff_nl + 1, *bsize - 1);
		else if (p_buff_nl < buff + *bsize - 1)
			ft_memmove(buff, p_buff_nl + 1, *bsize - (p_buff_nl - buff) - 1);
		*bsize -= (p_buff_nl - buff) + 1;
		return (new_size);
	}
	new_size += *bsize;
	*tab = ft_exallocf(*tab, size, new_size);
	if (!*tab)
		return (0);
	ft_memncat(*tab, size, buff, new_size - size);
	*bsize = 0;
	return (new_size);
}

/*
 *	Fill tab pointer with the next line
 */
size_t fill_tab_nextline(void **tab, ssize_t size, int *fd)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t rbytes;

	if (rbytes)
		size = fill_frombuffer(tab, size, buffer, &rbytes);
	if (ft_memchr(*tab, '\n', size))
		return (size);
	rbytes = read(*fd, buffer, BUFFER_SIZE);
	if (!rbytes)
		return (size);
	else
		size = fill_tab_nextline(tab, size, fd);
	return (size);
}

/*
 *	Returns the next line from a file as a string, containing \n.
 *	This functions use creates a static from fd, looping this
 *	functions sends each newline from last one, until EOF char.
 */
char *get_next_line(int fd)
{
	char *output;
	char **p_output;
	ssize_t tabsize;
	static int s_fd;

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

int main(void)
{
	char *line;
	int fd;
	int i;

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
