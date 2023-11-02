/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:05:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/01 18:09:24 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = lst->next;
	ft_lstdelone(lst, del);
	return (tmp);
}
