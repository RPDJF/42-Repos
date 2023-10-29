/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:31:00 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/29 20:33:12 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garbage_collector	*ft_garbage_add(t_garbage_collector gc, void *mem)
{
	ft_mempush(gc.collector, gc.size, mem);
}
