/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:21:28 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/12 10:02:53 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*reader;
	size_t	setcounter;

	setcounter = 0;
	reader = (char *)s1;
	while (*reader)
	{
		if(*reader == *set)
			setcounter++;
		reader++;
	}
	p = ft_calloc(ft_strlen(s1) - setcounter, sizeof(char));
	while (s1)
	{
		if (*s1 == *set)
		{
			s1++;
			continue;
		}
		*p++ = *s1++;

	}
	return (p);
}

// Check if same as real strtrim

int main(void)
{
	char s1[] = "H e l l o";
	char set[] = " ";

	printf("%s\n", ft_strtrim(s1, setS));
	return (0);
}