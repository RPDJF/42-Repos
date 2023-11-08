/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 20:50:11 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_list **src, t_list **dst)
{
	t_list	*swap;

	swap = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = swap;
}

void	go_to(t_stacks *stacks, int move_a, int move_b)
{
	while (!(move_a > (stacks->size_a / 2))
		&& !(move_b > (stacks->size_b / 2)) && move_a && move_b)
	{
		handler("rr", stacks);
		move_a--;
		move_b--;
	}
	while (move_a > (stacks->size_a / 2) && move_b > (stacks->size_b / 2)
		&& move_a < stacks->size_a && move_b < stacks->size_b)
	{
		handler("rrr", stacks);
		move_a++;
		move_b++;
	}
	while (move_a > (stacks->size_a / 2) && move_a++ < stacks->size_a)
		handler("rra", stacks);
	while (!(move_a > (stacks->size_a / 2)) && move_a--)
		handler("ra", stacks);
	while (move_b > (stacks->size_b / 2) && move_b++ < stacks->size_b)
		handler("rrb", stacks);
	while (!(move_b > (stacks->size_b / 2)) && move_b--)
		handler("rb", stacks);
}

int	sim_go_to(t_stacks *stacks, int move_a, int move_b)
{
	int	count;

	count = -2;
	while (count++, (!(move_a > (stacks->size_a / 2))
			&& !(move_b > (stacks->size_b / 2))) && (move_a && move_b))
	{
		move_a--;
		move_b--;
	}
	while (count++, move_a > stacks->size_a / 2 && move_b > stacks->size_b / 2
		&& move_a < stacks->size_a && move_b < stacks->size_b)
	{
		move_a++;
		move_b++;
	}
	while (move_a > (stacks->size_a / 2) && move_a++ < stacks->size_a)
		count++;
	while (!(move_a > (stacks->size_a / 2)) && move_a--)
		count++;
	while (move_b > (stacks->size_b / 2) && move_b++ < stacks->size_b)
		count++;
	while (!(move_b > (stacks->size_b / 2)) && move_b--)
		count++;
	return (count);
}

void	turc_move(t_stacks *stacks)
{
	int	moveset[2];
	int	i;
	int	current_cost;
	int	tmp[2];

	i = 0;
	while (i < stacks->size_a)
	{
		tmp[0] = getnear(*stacks, 'b', *ft_lstget(stacks->a, i));
		tmp[1] = sim_go_to(stacks, i, tmp[0]);
		if (!i || tmp[1] < current_cost)
		{
			current_cost = tmp[1];
			moveset[0] = i;
			moveset[1] = tmp[0];
		}
		if (current_cost <= 1)
			break ;
		i++;
	}
	go_to(stacks, moveset[0], moveset[1]);
}

/*void	print_stacks(t_stacks stacks)
{
	if (stacks.a)
		ft_printf("%d", *((int *)stacks.a->content));
	if (stacks.a)
		stacks.a = stacks.a->next;
	if (stacks.b)
		ft_printf("\t%d", *((int *)stacks.b->content));
	if (stacks.b)
		stacks.b = stacks.b->next;
	ft_printf("\n");
	if (!stacks.b && !stacks.a)
		ft_printf("_\t_\na\tb\n\n");
	if (stacks.a || stacks.b)
		print_stacks(stacks);
}
*/