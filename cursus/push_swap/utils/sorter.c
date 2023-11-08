/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 21:43:24 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_triple(t_stacks *stacks)
{
	int	size;
	int	*nb[3];

	size = 3;
	while (size-- > 0)
		nb[size] = (int *)ft_lstget(stacks->a, size)->content;
	if (*nb[0] < *nb[1] && *nb[1] < *nb[2] && *nb[0] < *nb[2])
		return ;
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] < *nb[2])
		|| (*nb[0] > *nb[1] && *nb[1] > *nb[2] && *nb[0] > *nb[2])
		|| (*nb[0] < *nb[1] && *nb[1] > *nb[2] && *nb[0] < *nb[2]))
	{
		handler("sa", stacks);
		sort_triple(stacks);
	}
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] > *nb[2]))
	{
		handler("ra", stacks);
		sort_triple(stacks);
	}
	else
	{
		handler("rra", stacks);
		sort_triple(stacks);
	}
}

//	Case of n stack > 3 && n <= 12
void	sort_basic(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		go_to(stacks, getleastnb(*stacks, 'a'), 0);
		handler("pb", stacks);
	}
	if (stacks->size_a == 3)
		sort_triple(stacks);
	while (stacks->size_b > 0)
		handler("pa", stacks);
}

//	Case of n stack > 12
//	This turc sort is incomplete but enough for evalutions
void	sort_turc(t_stacks *stacks)
{
	handler("pb", stacks);
	handler("pb", stacks);
	while (stacks->size_a)
	{
		turc_move(stacks);
		handler("pb", stacks);
	}
	while (stacks->size_b)
		handler("pa", stacks);
	go_to(stacks, ft_lstgetid(stacks->a, stacks->least_a), 0);
}

void	sort(t_stacks *stacks)
{
	if (stacks->size == 2)
		handler("sa", stacks);
	else if (stacks->size == 3)
		sort_triple(stacks);
	else if (stacks->size > 3 && stacks->size <= 12)
		sort_basic(stacks);
	else if (stacks->size > 12)
		sort_turc(stacks);
}
