/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/06 23:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
