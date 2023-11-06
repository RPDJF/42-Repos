/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/06 23:04:27 by marvin           ###   ########.fr       */
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
int	*get_bestmove(t_list *a, t_list *b)
{
	int	*output;
	int	i;
	int	current_cost;
	int	tmp[2];

	output = (int *)ft_calloc(2, sizeof(int));
	if (!output)
		return (0);
	i = 0;
	while (i < ft_lstsize(a))
	{
		tmp[0] = getnear(b, *ft_lstget(a, i));
		tmp[1] = sim_go_to(a, b, "a", i) + sim_go_to(a, b, "b", tmp[0]);
		if (*((int *)(ft_lstget(a, i)->content))
			< *((int *)ft_lstget(b, tmp[0])->content))
			tmp[1]++;
		if (!i || tmp[1] < current_cost)
		{
			current_cost = tmp[1];
			output[0] = i;
			output[1] = tmp[0];
		}
		i++;
	}
	return (output);
}

//	Case of n stack <= 10
int	sort_turc(t_list **a, t_list **b)
{
	int	*tmp;
	int	lstsize;
	int	i;

	handler("pb", a, b, 0);
	handler("pb", a, b, 0);
	lstsize = ft_lstsize(*a);
	i = 0;
	while (lstsize - i)
	{
		tmp = get_bestmove(*a, *b);
		go_to(a, b, "a", tmp[0]);
		go_to(a, b, "b", tmp[1]);
		handler("pb", a, b, 0);
		if (*((int *)(ft_lstget(*b, 1))->content) > *((int *)(*b)->content))
			handler("sb", a, b, 0);
		free(tmp);
		i++;
	}
	lstsize = ft_lstsize(*b);
	i = 0;
	while (i++, lstsize - i + 1)
		handler("pa", a, b, 0);
	go_to(a, b, "a", getleastnb(*a));
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
		sort_turc(a, b);
}
