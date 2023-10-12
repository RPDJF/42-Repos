/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:25 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/12 11:26:32 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if(!p)
		return (0);
	ft_bzero(p, count);
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