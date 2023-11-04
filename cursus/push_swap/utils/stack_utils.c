/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/04 13:20:01 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	getleastnb(t_list *stack)
{
	int	idx;
	int	size;
	int	nb;

	size = ft_lstsize(stack) - 1;
	nb = *((int *)ft_lstlast(stack)->content);
	idx = size;
	while (size-- > 0)
	{
		if (*((int *)ft_lstget(stack, size)->content) < nb)
		{
			nb = *((int *)ft_lstget(stack, size)->content);
			idx = size;
		}
	}
	return (idx);
}

void	push_stack(t_list **src, t_list **dst)
{
	t_list	*swap;

	swap = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = swap;
}

t_list	*arg2stack(char **tab)
{
	t_list	*head;
	int		*content;

	head = 0;
	while (tab && *tab)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_lstclear(&head, free);
		if (!content)
			return (0);
		*content = ft_atoi(*tab);
		head = ft_lstadd(head, content);
		if (!head)
			return (0);
		tab++;
	}
	return (head);
}
