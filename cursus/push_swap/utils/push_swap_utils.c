/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:50 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 17:02:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// take the first int of src and gives it to dst
int	push_stack(t_list **src, t_list **dst)
{
	void	*content;

	if (!*src)
		return (0);
	content = (void *)malloc(2 * sizeof(int));
	if (!content)
		return (-1);
	*((int *)content) = *((int *)(*src)->content);
	if (*dst)
		*dst = ft_lstpush(*dst, content);
	else
		*dst = ft_lstnew(content);
	*src = ft_lstpop(*src, free);
	return (0);
}

//	Handles all of the operations
int	handler(char	*operation, t_list **a, t_list	**b)
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
			return (simple_handler(operation, a, b));
		else if (operation[1] == 'b')
			return (simple_handler(operation, b, a));
		else
			if (simple_handler(operation, a, b) < 0
				|| simple_handler(operation, a, b) < 0)
				return (-1);
	}
	return (0);
}

//	Handles simple operations where operation has len of 2
int	simple_handler(char	*operation, t_list **src, t_list **dst)
{
	if (operation[0] == 's')
		*src = ft_lstswap(*src);
	else if (operation[0] == 'p')
		return (push_stack(dst, src));
	else if (operation[0] == 'r')
		*src = ft_lstrotate(*src);
	return (0);
}
