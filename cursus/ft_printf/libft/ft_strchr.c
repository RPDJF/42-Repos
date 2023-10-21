/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:42:45 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/17 12:23:33 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s)
		return ((char *)s);
	return (0);
}

// check if same as strchr
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "123456789";

	printf("FT:\t%s\n", ft_strchr(str, '\0'));
	printf("Real:\t%s\n", strchr(str, '\0'));
	return (0);
}
*/