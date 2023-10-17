/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:21:28 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 10:48:14 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkcharset(char const c, char const *set)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && checkcharset(s1[start], set))
		start++;
	while (end > 0 && s1[end] && checkcharset(s1[end], set))
		end--;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

// Check if same as real strtrim
/*#include <stdio.h>

int main(void)
{
	char s1[] = "d  ff    d";
	char set[] = "d";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/