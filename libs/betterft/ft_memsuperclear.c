/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsuperclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:57:23 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 18:07:38 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"
/*
*	Clears gallocs containing gallocs
*	**m is a pointer to the super galloc
*	size is the count of inside gallocs
*	**m entries should be pointers to galloc or null values
*/
void	ft_memsuperclear(void **m, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		gfree(m[i++]);
	gfree(m);
}
