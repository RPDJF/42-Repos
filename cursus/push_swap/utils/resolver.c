/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:22:38 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/05 14:22:38 by rude-jes         ###   ########.fr       */
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

int	getnearest(t_list *stack, int value)
{
	int	idx;
	int	size;
	int diff;

	size = ft_lstsize(stack);
	diff = 0;
	idx = -1;
	while (size-- > 0)
	{
		if (*((int *)ft_lstget(stack, size)->content) > value)
		{
			if (!diff || *((int *)ft_lstget(stack, size)->content) - value < diff)
			{
				diff = *((int *)ft_lstget(stack, size)->content) - value;
				idx = size;
			}
		}
		else if (!diff && *((int *)ft_lstget(stack, size)->content) == value)
			idx = size;
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
		if(*((int *)ft_lstget(stack, size)->content) == value)
			return (getnode(stack, *((int *)stack->content)));
	return (-1);
}
