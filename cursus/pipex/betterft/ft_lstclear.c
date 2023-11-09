/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:12:18 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstreader;

	lstreader = *lst;
	while (*lst)
	{
		lstreader = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lstreader;
	}
	*lst = 0;
}
