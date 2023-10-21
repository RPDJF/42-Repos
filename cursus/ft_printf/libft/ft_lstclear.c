/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:12:18 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/15 17:32:25 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
