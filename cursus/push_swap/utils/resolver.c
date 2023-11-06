/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:22:38 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/06 18:42:36 by rude-jes         ###   ########.fr       */
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

int	getmostnb(t_list *stack)
{
	int	idx;
	int	size;
	int	nb;

	size = ft_lstsize(stack) - 1;
	nb = *((int *)ft_lstlast(stack)->content);
	idx = size;
	while (size-- > 0)
	{
		if (*((int *)ft_lstget(stack, size)->content) > nb)
		{
			nb = *((int *)ft_lstget(stack, size)->content);
			idx = size;
		}
	}
	return (idx);
}

// erreure ici
int	getnear(t_list *stack, t_list node)
{
	int	idx;
	int	size;
	int	value;
	int	current;
	int	tmp;

	idx = -1;
	value = *((int *)node.content);
	size = ft_lstsize(stack);
	current = 0;
	while (size-- > 0)
	{
		tmp = *((int *)ft_lstget(stack, size)->content);
		if ((idx < 0 && tmp > value) || (tmp > value && tmp < current))
		{
			current = tmp;
			idx = size;
		}
	}
	if (idx < 0)
		idx = getmostnb(stack);
	return (idx);
}

int	getnode(t_list *stack, int value)
{
	int	size;

	size = ft_lstsize(stack);
	while (size-- > 0)
		if (*((int *)ft_lstget(stack, size)->content) == value)
			return (getnode(stack, *((int *)stack->content)));
	return (-1);
}
