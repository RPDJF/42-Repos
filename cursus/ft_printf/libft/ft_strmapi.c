/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:48:57 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/14 21:17:36 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	char			*owriter;

	output = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (0);
	owriter = output;
	while (owriter++, *(s++))
		*(owriter - 1) = f(owriter - 1 - output, *(s - 1));
	return (output);
}
