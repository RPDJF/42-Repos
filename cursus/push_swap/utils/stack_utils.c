/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/04 15:42:32 by rude-jes         ###   ########.fr       */
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
	char	*itoa;

	head = 0;
	while (tab && *tab)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			return (0);
		*content = ft_atoi(*tab);
		itoa = ft_itoa(*content);
		if (ft_strncmp(*tab, itoa, ft_strlen(*tab)))
		{
			free(content);
			free(itoa);
			return (0);
		}
		free(itoa);
		head = ft_lstadd(head, content);
		if (!head)
			return (0);
		tab++;
	}
	return (head);
}
