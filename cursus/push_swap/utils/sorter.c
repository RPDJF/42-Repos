/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/07 14:47:46 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_triple(t_list **a)
{
	int	size;
	int	*nb[3];

	size = 3;
	while (size-- > 0)
		nb[size] = (int *)ft_lstget(*a, size)->content;
	if (*nb[0] < *nb[1] && *nb[1] < *nb[2] && *nb[0] < *nb[2])
		return ;
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] < *nb[2])
		|| (*nb[0] > *nb[1] && *nb[1] > *nb[2] && *nb[0] > *nb[2])
		|| (*nb[0] < *nb[1] && *nb[1] > *nb[2] && *nb[0] < *nb[2]))
	{
		handler("sa", a, 0, 0);
		sort_triple(a);
	}
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] > *nb[2]))
	{
		handler("ra", a, 0, 0);
		sort_triple(a);
	}
	else
	{
		handler("rra", a, 0, 0);
		sort_triple(a);
	}
}

//	Pour chaque nombre dans A
//		Calculer cout deplacement (sim_go_to)
//		Ajouter cout deplacement B pour bonne position sim_go_to + get_near
//			Si nombre plus petit que nearest B, ajouter 1 pour le sb
void	get_bestmove(t_list **a, t_list **b, int size_a, int size_b)
{
	int	output[2];
	int	i;
	int	current_cost;
	int	tmp[2];

	i = 0;
	while (i < size_a)
	{
		tmp[0] = getnear(*b, size_b, *ft_lstget(*a, i));
		tmp[1] = sim_go_to(size_a, i) + sim_go_to(size_b, tmp[0]);
		if (*((int *)(ft_lstget(*a, i)->content))
			< *((int *)ft_lstget(*b, tmp[0])->content))
			tmp[1]++;
		if (!i || tmp[1] < current_cost)
		{
			current_cost = tmp[1];
			output[0] = i;
			output[1] = tmp[0];
		}
		i++;
	}
	go_to(a, "a", size_a, output[0]);
	go_to(b, "b", size_b, output[1]);
}

//	Case of n stack <= 10
int	sort_turc(t_list **a, t_list **b, int lstsize)
{
	int	i;

	handler("pb", a, b, 0);
	handler("pb", a, b, 0);
	lstsize -= 2;
	i = 0;
	while (lstsize - i)
	{
		get_bestmove(a, b, lstsize - i, 2 + i);
		handler("pb", a, b, 0);
		i++;
	}
	while (2 + i)
	{
		handler("pa", a, b, 0);
		i--;
	}
	go_to(a, "a", lstsize + 2, getleastnb(*a, lstsize + 2));
	return (1);
}

void	sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		handler("sa", a, b, 0);
	else if (size == 3)
		sort_triple(a);
	else if (size > 3)
		sort_turc(a, b, size);
}
