/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:41:46 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/17 18:13:02 by rude-jes         ###   ########.fr       */
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
*	Different from LIBFT > do not use ft_calloc
*	It frees the source pointer (*s)
*/
char	*ft_substrf(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		p = (char *)malloc(sizeof(char));
		*p = 0;
		return (p);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (i++ < len + 1)
		p[i - 1] = 0;
	ft_memcpy(p, s + start, len);
	free(s);
	return (p);
}

/*
*	Modified strlen which return null if str is null
*/
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*
* The strncat() function appends not more than n characters from s2, and then
* adds a terminating `\0'.
* The source and destination strings should not overlap, as the behavior is
* undefined.
* The strncat() function returns the pointer s1.
*/
char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while ((unsigned int)j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
