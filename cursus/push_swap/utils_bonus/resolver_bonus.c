/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:22:38 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 23:53:58 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
