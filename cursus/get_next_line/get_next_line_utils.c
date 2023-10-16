/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:41:46 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/16 22:12:03 by rude-jes         ###   ########.fr       */
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
* Returns 0 if allocation failed
*/
void	*ft_exallocf(void *ptr, size_t size, size_t newsize)
{
	void	*p;
	void	*pwriter;

	p = malloc(newsize);
	if (!p)
		return (0);
	pwriter = p;
	if (!ptr)
	{
		while (pwriter++ - p < newsize)
			*((unsigned char *)(pwriter - 1)) = 0;
		return (p);
	}
	while (pwriter++ - p < size)
	{
		*((unsigned char *)(pwriter - 1)) = *((unsigned char *)ptr);
		pwriter++;
	}
	free(ptr);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s)
		return ((char *)s);
	return (0);
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;

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
	ft_memcpy(p, s + start, len);
	return (p);
}
