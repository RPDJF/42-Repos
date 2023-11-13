/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:12 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

t_list	*ft_lstrotate(t_list *lst)
{
	t_list	*tmp;

	if (ft_lstsize(lst) < 2)
		return (lst);
	tmp = lst;
	lst = lst->next;
	ft_lstlast(lst)->next = tmp;
	tmp->next = 0;
	return (lst);
}
