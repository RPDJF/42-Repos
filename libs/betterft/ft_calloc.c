/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:25 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count * size > (size_t)2147483647)
		return (0);
	p = galloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}
