/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:19:05 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/20 13:19:16 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memtostr(void *mem, size_t size)
{
	char	eos;

	eos = '\0';
	mem = ft_exallocf(mem, size, size + 1);
	if (!mem)
		return (0);
	((unsigned char *)mem)[size] = eos;
	return ((char *)mem);
}
