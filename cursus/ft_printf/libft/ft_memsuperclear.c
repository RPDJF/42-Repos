/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsuperclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:57:23 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/17 11:59:22 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*	Clears mallocs containing mallocs
*	**m is a pointer to the super malloc
*	size is the count of inside mallocs
*	**m entries should be pointers to malloc or null values
*/
void	ft_memsuperclear(void **m, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
}
