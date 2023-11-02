/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 16:55:08 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrevrotate(t_list *lst)
{
	t_list	*tmp;

	if (ft_lstsize(lst) < 2)
		return (lst);
	tmp = ft_lstget(lst, ft_lstsize(lst) - 2);
	ft_lstadd_front(&lst, ft_lstlast(lst));
	tmp->next = 0;
	return (lst);
}
