/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:02:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/29 20:07:18 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempush(void *mem, size_t size, int byte)
{
	void	*p;

	p = ft_exallocf(mem, size, size + 1);
	if (!p)
		return (0);
	ft_memmove(p, mem, size);
	((unsigned char *)p)[size] = byte;
	return (p);
}
