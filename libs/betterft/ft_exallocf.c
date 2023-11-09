/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:17:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 18:01:17 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

void	*ft_exallocf(void *ptr, size_t size, size_t newsize)
{
	void	*p;
	void	*p_p;

	p = galloc(newsize);
	if (!p)
	{
		gfree(ptr);
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
	gfree(ptr);
	return (p);
}
