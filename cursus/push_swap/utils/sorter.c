/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/07 17:18:16 by rude-jes         ###   ########.fr       */
=======
/*   Updated: 2023/11/07 14:47:46 by rude-jes         ###   ########.fr       */
>>>>>>> 429e7549181b69ccd052486fcea4c95e4e1ed8a9
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
<<<<<<< HEAD
		tmp[0] = getnear(stacks->b, *ft_lstget(stacks->a, i));
		tmp[1] = sim_go_to(stacks, "a", i) + sim_go_to(stacks, "b", tmp[0]);
		if (*((int *)(ft_lstget(stacks->a, i)->content))
			< *((int *)ft_lstget(stacks->b, tmp[0])->content))
=======
		tmp[0] = getnear(*b, size_b, *ft_lstget(*a, i));
		tmp[1] = sim_go_to(size_a, i) + sim_go_to(size_b, tmp[0]);
		if (*((int *)(ft_lstget(*a, i)->content))
			< *((int *)ft_lstget(*b, tmp[0])->content))
>>>>>>> 429e7549181b69ccd052486fcea4c95e4e1ed8a9
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
<<<<<<< HEAD
int	sort_turc(t_stacks *stacks)
{
	int	lstsize;

	handler("pb", stacks, 0);
	handler("pb", stacks, 0);
	lstsize = stacks->size;
	while (stacks->size_a)
=======
int	sort_turc(t_list **a, t_list **b, int lstsize)
{
	int	i;

	handler("pb", a, b, 0);
	handler("pb", a, b, 0);
	lstsize -= 2;
	i = 0;
	while (lstsize - i)
>>>>>>> 429e7549181b69ccd052486fcea4c95e4e1ed8a9
	{
		get_bestmove(stacks);
		handler("pb", stacks, 0);
	}
<<<<<<< HEAD
	while (stacks->size_b)
		handler("pa", stacks, 0);
	go_to(stacks, "a", getleastnb(stacks->a));
=======
	while (2 + i)
	{
		handler("pa", a, b, 0);
		i--;
	}
	go_to(a, "a", lstsize + 2, getleastnb(*a, lstsize + 2));
>>>>>>> 429e7549181b69ccd052486fcea4c95e4e1ed8a9
	return (1);
}

void	sort(t_stacks *stacks)
{
<<<<<<< HEAD
	if (stacks->size == 2)
		handler("sa", stacks, 0);
	else if (stacks->size == 3)
		sort_triple(stacks);
	else if (stacks->size > 3)
		sort_turc(stacks);
=======
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		handler("sa", a, b, 0);
	else if (size == 3)
		sort_triple(a);
	else if (size > 3)
		sort_turc(a, b, size);
>>>>>>> 429e7549181b69ccd052486fcea4c95e4e1ed8a9
}
