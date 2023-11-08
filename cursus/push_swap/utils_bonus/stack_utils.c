/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 23:52:24 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	push_stack(t_list **src, t_list **dst)
{
	t_list	*swap;

	swap = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = swap;
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