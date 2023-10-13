/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:25 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 11:20:35 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The calloc() function contiguously allocates enough space for count objects
** that are size bytes of memory each and returns a pointer to the allocated
** memory.  The allocated memory is filled with bytes of value zero.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count * size > (size_t)2147483647)
		return (0);
	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

// check if same as calloc
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	// check visually if same as calloc
	char	*str;
	char	*str2;

	str = ft_calloc(10, sizeof(char));
	str2 = calloc(10, sizeof(char));
	printf("ft: %s\n", str);
	printf("real: %s\n", str2);
	
	return (0);
}
*/