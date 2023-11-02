/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:05:00 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/01 18:05:20 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list *lst, void *content)
{
	t_list	*newlist;

	newlist = ft_lstnew(content);
	if (!newlist)
		return (0);
	ft_lstadd_front(&lst, newlist);
	return (lst);
}
