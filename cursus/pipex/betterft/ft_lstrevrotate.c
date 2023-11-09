/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

t_list	*ft_lstrevrotate(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize(lst);
	if (size < 2)
		return (lst);
	tmp = ft_lstget(lst, size - 2);
	ft_lstadd_front(&lst, ft_lstlast(lst));
	tmp->next = 0;
	return (lst);
}
