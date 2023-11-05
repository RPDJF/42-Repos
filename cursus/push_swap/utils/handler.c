/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:50 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/05 18:10:39 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_handler(char	*operation, t_list **src, t_list **dst)
{
	if (operation[0] == 's')
		*src = ft_lstswap(*src);
	else if (operation[0] == 'p')
		push_stack(dst, src);
	else if (operation[0] == 'r')
		*src = ft_lstrotate(*src);
}

int	handler(char *operation, t_list **a, t_list	**b)
{
	ft_printf("%s\n", operation);
	if (ft_strlen(operation) == 3)
	{
		if (operation[2] == 'a')
			*a = ft_lstrevrotate(*a);
		else if (operation[2] == 'b')
			*b = ft_lstrevrotate(*b);
		else
		{
			*a = ft_lstrevrotate(*a);
			*b = ft_lstrevrotate(*b);
		}
	}
	else
	{
		if (operation[1] == 'a')
			simple_handler(operation, a, b);
		else if (operation[1] == 'b')
			simple_handler(operation, b, a);
	}
	/*if (b)
		print_stacks(*a, *b);
	else
		print_stacks(*a, 0);*/
	return (0);
}
