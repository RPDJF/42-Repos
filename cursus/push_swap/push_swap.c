/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 18:44:29 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*parse_args(char **args, size_t size)
{
	t_list	*stack;
	t_list	*tmp;
	int		*content;

	stack = 0;
	while (size--)
	{
		content = (int *)malloc(2 * sizeof(int));
		if (!content)
			ft_lstclear(&stack, free);
		if (!content)
			return (0);
		*content = ft_atoi(args[size]);
		tmp = ft_lstnew((void *)content);
		if (!tmp)
			ft_lstclear(&stack, free);
		if (!tmp)
			return (0);
		ft_lstadd_front(&stack, tmp);
	}
	return (stack);
}

// need to check for duplicas
int	main(int argc, char **argv)
{
	int		lstsize;
	t_list	*a;
	t_list	*b;

	a = parse_args(argv + 1, argc - 1);
	if (!a)
		return (0);
	b = 0;
	lstsize = ft_lstsize(a);
	if (lstsize == 3)
		sort_triple(&a);
	else if (lstsize <= 10)
		sort_ten(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

// for debug purpose
/*static int	print_content(void *content)
{
	if (content)
		return (ft_printf("%d\t", *((int *)content)));
	return (0);
}
*/