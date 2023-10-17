/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:25:04 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/15 12:32:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	return (p);
}
