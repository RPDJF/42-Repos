/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:18:07 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/20 13:18:44 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memncat(void *dest, size_t start, void *src, size_t nb)
{
	int	i;

	if (!dest)
		return (0);
	i = 0;
	while ((unsigned int)i < nb)
	{
		((unsigned char *)dest)[start + i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
