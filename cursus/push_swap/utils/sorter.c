/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/06 18:57:26 by rude-jes         ###   ########.fr       */
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
	int	tmp;

	output = (int *)ft_calloc(2, sizeof(int));
	if (!output)
		return (0);
	i = 0;
	while (i < ft_lstsize(a))
	{
		tmp = sim_go_to(a, b, "a", i)
			+ sim_go_to(a, b, "b", getnear(b, *ft_lstget(a, i)));
		if (*((int *)(ft_lstget(a, i)->content))
			< *((int *)ft_lstget(b, getnear(b, *ft_lstget(a, i)))->content))
			tmp++;
		if (!i || tmp < current_cost)
		{
			current_cost = tmp;
			output[0] = i;
			output[1] = getnear(b, *ft_lstget(a, i));
		}
		i++;
	}
	return (output);
}

//	Case of n stack <= 10
int	sort_turc(t_list **a, t_list **b)
{
	int	size;
	int	*bestmove;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	while (!check_stackorder(*a))
	{
		bestmove = get_bestmove(*a, *b);
		if (!bestmove)
			return (-1);
		go_to(a, b, "a", bestmove[0]);
		go_to(a, b, "b", bestmove[1]);
		handler("pb", a, b, 0);
	}
	size = ft_lstsize(*b);
	while (size-- > 0)
		handler("pa", a, b, 0);
	return (0);
}

/*
//	Case of n stack  <= 100
int	sort_hundred(t_list **a, t_list **b)
{

}

//	Case of n stack > 100
//	May be less optimized than using sort_triple, sort_turc and sort_hundred
int	sort_plus(t_list **a, t_list **b)
{
	
}
*/

void	sort(t_list **a, t_list **b)
{
	int	*tmp;
	int	lstsize;

	lstsize = ft_lstsize(*a);
	if (lstsize == 3)
		sort_triple(a);
	else if (lstsize)
	{
		handler("pb", a, b, 0);
		handler("pb", a, b, 0);
		while (ft_lstsize(*a))
		{
			tmp = get_bestmove(*a, *b);
			//print_stacks(*a, *b);
			//ft_printf("\nBest A\t%d\nBest B\t%d\n", tmp[0], tmp[1]);
			go_to(a, b, "a", tmp[0]);
			go_to(a, b, "b", tmp[1]);
			handler("pb", a, b, 0);
			if (*((int *)(ft_lstget(*b, 1))->content) > *((int *)(*b)->content))
				handler("sb", a, b, 0);
			free(tmp);
		}
		while (ft_lstsize(*b))
			handler("pa", a, b, 0);
		go_to(a, b, "a", getleastnb(*a));
		//sort_turc(a, b);
	}
	
}
