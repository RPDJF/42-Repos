/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:27:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 01:29:18 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dstwriter;

	if (!dest && !src)
		return (0);
	dstwriter = dest;
	while (src++, dstwriter++, (size_t)dstwriter - 1 - (size_t)dest < n)
		*(dstwriter - 1) = *(unsigned char *)(src - 1);
	return (dest);
}
