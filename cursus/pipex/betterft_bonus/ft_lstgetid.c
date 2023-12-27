/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:12:13 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 21:12:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

int	ft_lstgetid(t_list *list, t_list *node)
{
	int	i;

	if (!node || !list)
		return (-1);
	i = -1;
	while (i++, list && list != node)
		list = list->next;
	if (list)
		return (i);
	return (-1);
}
