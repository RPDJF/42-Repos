/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_orchestror.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:43:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 18:44:22 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Case of n stack = 3
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
		handler("sa", a, 0);
		sort_triple(a);
	}
	else if ((*nb[0] > *nb[1] && *nb[1] < *nb[2] && *nb[0] > *nb[2]))
	{
		handler("ra", a, 0);
		sort_triple(a);
	}
	else
	{
		handler("rra", a, 0);
		sort_triple(a);
	}
}

//	Case of n stack <= 10
int	sort_ten(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (!check_lstorder(*a))
	{
		while (getleastnb(*a))
		{
			if (getleastnb(*a) > (size / 2))
				handler("rra", a, b);
			else
				handler("ra", a, b);
		}
		handler("pb", a, b);
	}
	size = ft_lstsize(*b);
	while (size-- > 0)
		handler("pa", a, b);
	return (0);
}

/*
//	Case of n stack  <= 100
int	sort_hundred(t_list **a, t_list **b)
{

}

//	Case of n stack > 100
//	May be less optimized than using sort_triple, sort_ten and sort_hundred
int	sort(t_list **a, t_list **b)
{
	
}
*/