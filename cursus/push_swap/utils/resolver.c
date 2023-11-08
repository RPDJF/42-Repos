/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:22:38 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 21:15:37 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*getstack(t_stacks stacks, char src)
{
	if (src == 'a')
		return (stacks.a);
	return (stacks.b);
}

int	getstacklen(t_stacks stacks, char src)
{
	if (src == 'a')
		return (stacks.size_a);
	return (stacks.size_b);
}

int	getleastnb(t_stacks stacks, char src)
{
	int	idx;
	int	size;
	int	nb;
	int	tmp;

	size = getstacklen(stacks, src) - 1;
	nb = *((int *)ft_lstlast(getstack(stacks, src))->content);
	idx = size;
	while (size-- > 0)
	{
		tmp = *((int *)ft_lstget(getstack(stacks, src), size)->content);
		if (tmp < nb)
		{
			nb = tmp;
			idx = size;
		}
	}
	return (idx);
}

int	getmostnb(t_stacks stacks, char src)
{
	int	idx;
	int	size;
	int	nb;
	int	tmp;

	size = getstacklen(stacks, src) - 1;
	nb = *((int *)stacks.last_a->content);
	if (src == 'b')
		nb = *((int *)stacks.last_b->content);
	idx = size;
	while (size-- > 0)
	{
		tmp = *((int *)ft_lstget(getstack(stacks, src), size)->content);
		if (tmp > nb)
		{
			nb = tmp;
			idx = size;
		}
	}
	return (idx);
}

int	getnear(t_stacks stacks, char src, t_list node)
{
	int	idx;
	int	value;
	int	current;
	int	tmp;
	int	size;

	idx = -1;
	value = *((int *)node.content);
	size = getstacklen(stacks, src);
	current = 0;
	while (size-- > 0)
	{
		tmp = *((int *)ft_lstget(getstack(stacks, src), size)->content);
		if ((idx < 0 && tmp < value) || (tmp < value && tmp > current))
		{
			current = tmp;
			idx = size;
		}
	}
	if (idx < 0 && src == 'a')
		idx = ft_lstgetid(stacks.a, stacks.most_a);
	else if (idx < 0 && src == 'b')
		idx = ft_lstgetid(stacks.b, stacks.most_b);
	return (idx);
}
