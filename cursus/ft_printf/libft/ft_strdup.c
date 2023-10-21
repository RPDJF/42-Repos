/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:37:35 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 00:10:50 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it. The pointer may subsequently be used as an
** argument to the function free(3). If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p_malloc;
	int		i;

	p_malloc = (char *)ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!p_malloc)
		return (0);
	i = 0;
	while (src[i++])
		p_malloc[i - 1] = src[i - 1];
	return (p_malloc);
}

// check if same as strdup
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	// check visually if same as strdup
	char	*str;
	char	*str2;

	str = ft_strdup("123456789");
	str2 = strdup("123456789");
	printf("ft: %s\n", str);
	printf("real: %s\n", str2);
	
	return (0);
}*/