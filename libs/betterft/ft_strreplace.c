/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:19:49 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/28 14:51:02 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

static size_t	count_replaces(char *src, char *old)
{
	size_t	count;
	char	*tmp;

	count = -1;
	tmp = ft_strnstr(src, old, ft_strlen(src));
	while (count++, tmp && *tmp)
		tmp = ft_strnstr(tmp + 1, old, ft_strlen(tmp + 1));
	return (count);
}

char	*ft_strreplace(char *src, char *old, char *new)
{
	char	*output;
	int		count;
	char	*tmp;
	size_t	size;

	count = count_replaces(src, old);
	if (!count)
		return (ft_strdup(src));
	size = ((ft_strlen(src) + (ft_strlen(new) - ft_strlen(old)) * count) + 1);
	output = galloc(size);
	if (!output)
		return (0);
	size = 0;
	tmp = ft_strnstr(src, old, ft_strlen(src));
	while (count--, count >= 0)
	{
		ft_strlcpy(output + size, src, tmp - src + 1);
		size += tmp - src;
		src += tmp - src;
		ft_strlcpy(output + size, new, ft_strlen(new) + 1);
		size += ft_strlen(new);
		src += ft_strlen(old);
		tmp = ft_strnstr(tmp + 1, old, ft_strlen(tmp + 1));
	}
	return (output);
}
