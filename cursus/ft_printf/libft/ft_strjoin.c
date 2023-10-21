/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:04:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/12 13:26:18 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	size1;
	size_t	size2;
	size_t	i;
	size_t	j;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < size1)
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size2)
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}

/*#include <stdio.h>

int    main(void)
{
	printf("%s\n", ft_strjoin("Hello", " bonjour."));
}
*/