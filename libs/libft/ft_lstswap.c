/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:52:07 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/01 17:52:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstswap(t_list *lst)
{
	void	*swap;

	if (ft_lstsize(lst) < 2)
		return (lst);
	swap = lst->content;
	lst->content = lst->next->content;
	lst->next->content = swap;
	return (lst);
}
