/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 15:07:25 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handler(char	*operation, t_list **a, t_list	**b)
{
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
		else
		{
			simple_handler(operation, a, b);
			simple_handler(operation, b, a);
		}
	}
	ft_printf("%s\n", operation);
}

static int	print_content(void *content)
{
	if (content)
		return (ft_printf("%d\n", *((int *)content)));
	return (0);
}

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

/*int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = 0;
	a = parse_args(argv + 1, argc - 1);
	if (!a)
		return (0);
	b = 0;

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("ra", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("rra", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("sa", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("sa", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pa", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pa", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pa", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	handler("pb", &a, &b);

	ft_printf("=====\n");
	ft_printf("a:\n");
	ft_lstiter(a, (void *)print_content);
	ft_printf("b:\n");
	ft_lstiter(b, (void *)print_content);
	ft_printf("=====\n\n");

	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
*/