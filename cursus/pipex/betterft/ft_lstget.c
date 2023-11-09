/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

t_list	*ft_lstget(t_list *lst, size_t idx)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (i < idx)
	{
		if (!lst->next)
			return (0);
		lst = lst->next;
		i++;
	}
	return (lst);
}
