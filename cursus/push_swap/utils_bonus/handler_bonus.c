/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:50 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 12:02:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	pushb_handler(t_stacks *stacks, t_list *src)
{
	if (stacks->size_a <= 0)
		secure_exit(stacks, "KO");
	stacks->size_a--;
	stacks->size_b++;
	if (!stacks->most_a || stacks->most_a == src)
		stacks->most_a = ft_lstget(stacks->a, getmostnb(*stacks, 'a'));
	else if (!stacks->least_a || stacks->least_a == src)
		stacks->least_a = ft_lstget(stacks->a, getleastnb(*stacks, 'a'));
	if (!stacks->most_b
		|| *((int *)src->content) > *((int *)stacks->most_b->content))
		stacks->most_b = src;
	else if (!stacks->least_b
		|| *((int *)src->content) < *((int *)stacks->least_b->content))
		stacks->least_b = src;
	if (!stacks->last_b)
		stacks->last_b = src;
}

void	pusha_handler(t_stacks *stacks, t_list *src)
{
	if (stacks->size_b <= 0)
		secure_exit(stacks, "KO");
	stacks->size_a++;
	stacks->size_b--;
	if (!stacks->most_b || stacks->most_b == src)
		stacks->most_b = ft_lstget(stacks->b, getmostnb(*stacks, 'b'));
	else if (!stacks->least_b || stacks->least_a == src)
		stacks->least_b = ft_lstget(stacks->b, getleastnb(*stacks, 'b'));
	if (!stacks->most_a
		|| *((int *)src->content) > *((int *)stacks->most_a->content))
		stacks->most_a = src;
	else if (!stacks->least_a
		|| *((int *)src->content) < *((int *)stacks->least_a->content))
		stacks->least_a = src;
}

void	rotate_handler(char stack, t_stacks *stacks, t_list **src, t_list **dst)
{
	if (stack == 'a')
		stacks->last_a = stacks->a;
	else if (stack == 'b')
		stacks->last_b = stacks->b;
	else
	{
		stacks->last_a = stacks->a;
		stacks->last_b = stacks->b;
		*dst = ft_lstrotate(*dst);
	}
	*src = ft_lstrotate(*src);
}

void	simple_handler(char	*operation, t_stacks *stacks)
{
	t_list	**src;
	t_list	**dst;

	src = &stacks->a;
	dst = &stacks->b;
	if (operation[1] == 'b')
		src = &stacks->b;
	if (operation[1] == 'b')
		dst = &stacks->a;
	if (operation[0] == 's')
		*src = ft_lstswap(*src);
	else if (operation[0] == 'p')
	{
		if (operation[1] == 'a')
			pusha_handler(stacks, *dst);
		else
			pushb_handler(stacks, *dst);
		push_stack(dst, src);
	}
	else if (operation[0] == 'r')
		rotate_handler(operation[1], stacks, src, dst);
}

void	handler(char *operation, t_stacks *stacks)
{
	if (ft_strlen(operation) == 3)
	{
		if (operation[2] == 'a')
		{
			stacks->a = ft_lstrevrotate(stacks->a);
			stacks->last_a = ft_lstlast(stacks->a);
		}
		else if (operation[2] == 'b')
		{
			stacks->b = ft_lstrevrotate(stacks->b);
			stacks->last_b = ft_lstlast(stacks->b);
		}
		else
		{
			stacks->a = ft_lstrevrotate(stacks->a);
			stacks->b = ft_lstrevrotate(stacks->b);
			stacks->last_a = ft_lstlast(stacks->a);
			stacks->last_b = ft_lstlast(stacks->b);
		}
	}
	else
		simple_handler(operation, stacks);
}
