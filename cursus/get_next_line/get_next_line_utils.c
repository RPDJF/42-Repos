/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:41:46 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/18 13:48:22 by rude-jes         ###   ########.fr       */
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
