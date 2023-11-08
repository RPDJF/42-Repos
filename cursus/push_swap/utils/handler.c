/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:50 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 13:28:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		push_stack(dst, src);
		if (operation[1] == 'a')
			stacks->size_a++;
		if (operation[1] == 'a')
			stacks->size_b--;
		if (operation[1] == 'b')
			stacks->size_a--;
		if (operation[1] == 'b')
			stacks->size_b++;
	}
	else if (operation[0] == 'r')
		*src = ft_lstrotate(*src);
}

int	handler(char *operation, t_stacks *stacks, int isheap)
{
	if (!operation)
		return (0);
	ft_printf("%s\n", operation);
	if (ft_strlen(operation) == 3)
	{
		if (operation[2] == 'a')
			stacks->a = ft_lstrevrotate(stacks->a);
		else if (operation[2] == 'b')
			stacks->b = ft_lstrevrotate(stacks->b);
		else
		{
			stacks->a = ft_lstrevrotate(stacks->a);
			stacks->b = ft_lstrevrotate(stacks->b);
		}
	}
	else
		simple_handler(operation, stacks);
	if (isheap)
		free (operation);
	//print_stacks(*stacks);
	return (1);
}
