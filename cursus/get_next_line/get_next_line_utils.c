/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:41:46 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/19 15:58:09 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Returns a pointer to an extend malloc
 *	Copies bytes from ptr to the returned malloc
 *	ft_exallocf frees the ptr's pointed malloc
 *
 *	Size inputs represents the size of the malloc in bytes
 *	If ptr is null, returns a new 'calloc' with newsize
 *	Returns 0 if allocation failed and free ptr
 */
void	*ft_exallocf(void *ptr, size_t size, size_t newsize)
{
	void	*p;
	void	*p_p;

	p = malloc(newsize);
	if (!p)
	{
		free(ptr);
		return (0);
	}
	p_p = p;
	if (!ptr)
	{
		while ((size_t)p_p++ - (size_t)p < newsize)
			*((unsigned char *)(p_p - 1)) = 0;
		return (p);
	}
	while ((size_t)p_p - (size_t)p < size)
	{
		*((unsigned char *)(p_p)) = *((unsigned char *)(ptr + (p_p - p)));
		p_p++;
	}
	while ((size_t)p_p - (size_t)p < newsize)
		*((unsigned char *)(p_p++)) = 0;
	free(ptr);
	return (p);
}

/*
*	ft_memmove copies n bytes from src to dest
*	It does protect the memory from overlapping
*	Returns dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

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
