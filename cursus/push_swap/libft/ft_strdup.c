/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:37:35 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 01:30:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it. The pointer may subsequently be used as an
** argument to the function free(3). If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p_malloc;
	int		i;

	p_malloc = (char *)ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!p_malloc)
		return (0);
	i = 0;
	while (src[i++])
		p_malloc[i - 1] = src[i - 1];
	return (p_malloc);
}
