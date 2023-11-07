/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/07 22:00:30 by rude-jes         ###   ########.fr       */
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
		handler("sa", stacks, 0);
		sort_triple(stacks);
	}
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] > *nb[2]))
	{
		handler("ra", stacks, 0);
		sort_triple(stacks);
	}
	else
	{
		handler("rra", stacks, 0);
		sort_triple(stacks);
	}
}

//	Pour chaque nombre dans A
//		Calculer cout deplacement (sim_go_to)
//		Ajouter cout deplacement B pour bonne position sim_go_to + get_near
//			Si nombre plus petit que nearest B, ajouter 1 pour le sb
void	get_bestmove(t_stacks *stacks)
{
	int	output[2];
	int	i;
	int	current_cost;
	int	tmp[2];

	i = 0;
	while (i < stacks->size_a)
	{
		tmp[0] = getnear(stacks->b, stacks->size_b, *ft_lstget(stacks->a, i));
		tmp[1] = sim_go_to(stacks, "a", i) + sim_go_to(stacks, "b", tmp[0]);
		if (*((int *)(ft_lstget(stacks->a, i)->content))
			< *((int *)ft_lstget(stacks->b, tmp[0])->content))
			tmp[1]++;
		if (!i || tmp[1] < current_cost)
		{
			current_cost = tmp[1];
			output[0] = i;
			output[1] = tmp[0];
		}
		i++;
	}
	go_to(stacks, "a", output[0]);
	go_to(stacks, "b", output[0]);
}

//	Case of n stack <= 10
int	sort_turc(t_stacks *stacks)
{
	handler("pb", stacks, 0);
	handler("pb", stacks, 0);
	while (stacks->size_a)
	{
		get_bestmove(stacks);
		handler("pb", stacks, 0);
	}
	while (stacks->size_b)
		handler("pa", stacks, 0);
	go_to(stacks, "a", getleastnb(stacks->a, stacks->size_a));
	return (1);
}

void	sort(t_stacks *stacks)
{
	if (stacks->size == 2)
		handler("sa", stacks, 0);
	else if (stacks->size == 3)
		sort_triple(stacks);
	else if (stacks->size > 3)
		sort_turc(stacks);
}
