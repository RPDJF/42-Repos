/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:42:45 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 20:39:22 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	last;

	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	i = 1;
	last = 0;
	while (s[i - 1])
	{
		if (s[i - 1] == (unsigned char)c)
			last = i;
		i++;
	}
	if (!last)
		return (0);
	return ((char *)s + last - 1);
}

// check if same as strrchr
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "1234567589";

	printf("%s\n", ft_strrchr(str, '5'));
	printf("%s\n", strrchr(str, '5'));
	return (0);
}
*/