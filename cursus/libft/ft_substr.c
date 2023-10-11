/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:07:41 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 10:19:46 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = 0;
	return (p);
}

/*#include <stdio.h>

int    main(void)
{
	char	*p;

	p = ft_substr("Bonjour", 3, 7);
	printf("%s\n", p);
	free(p);
}
*/