/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:37:35 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 10:10:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*p_malloc;
	int		i;

	i = 0;
	while (src[i])
		i++;
	p_malloc = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		p_malloc[i] = src[i];
		i++;
	}
	p_malloc[i] = 0;
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