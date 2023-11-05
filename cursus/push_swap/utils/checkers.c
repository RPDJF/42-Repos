/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:28 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/05 16:04:23 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_stackorder(t_list *stack)
{
	int	nb;
	int	size;

	size = ft_lstsize(stack) - 1;
	nb = *((int *)ft_lstlast(stack)->content);
	while (size-- > 0)
	{
		if (*((int *)ft_lstget(stack, size)->content) > nb)
			return (0);
		nb = *((int *)ft_lstget(stack, size)->content);
	}
	return (1);
}

int	check_duplicates(t_list *head)
{
	t_list	*next;

	if (!head)
		return (0);
	next = head->next;
	while (next)
	{
		if (*((int *)(head->content)) == *((int *)(next->content)))
			return (0);
		next = next->next;
	}
	if (head->next)
		return (check_duplicates(head->next));
	return (1);
}

int	check_input(char **args, size_t size)
{
	size_t			strsize;

	while (size-- > 0)
	{
		strsize = ft_strlen(args[size]);
		while (strsize-- > 0)
			if (!ft_isdigit(args[size][strsize]))
				if (args[size][strsize] != ' ')
					if (!(args[size][strsize] == '-'
						&& ft_isdigit(args[size][strsize + 1])))
						return (0);
	}
	return (1);
}
