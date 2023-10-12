/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:21:28 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/12 23:00:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkcharset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && checkcharset(s1[start], set))
		start++;
	while (end >= 0 && s1[end] && checkcharset(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

// Check if same as real strtrim
#include <stdio.h>

int main(void)
{
	char s1[] = "       ";
	char set[] = " ";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
