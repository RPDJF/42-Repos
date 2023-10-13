/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:07:41 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 11:38:33 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION	The  substr() function extracts a substring from the string 's'.
	The substring begins at position 'start' and is of maximum size 'len'.

	RETURN VALUES	If the allocation fails, the function returns NULL.
	Otherwise, it returns a pointer to the substring.
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!s)
		return (0);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		p[i] = s[i + start];
		i++;
	}
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