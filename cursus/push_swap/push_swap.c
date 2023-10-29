/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/29 16:27:36 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_args(char **args, size_t size)
{
	int	*stack;

	stack = (int *)malloc(size * sizeof(int));
	if (!stack)
		return (0);
	while (size--)
		stack[size] = ft_atoi(args[size]);
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_a;

	stack_a = parse_args(argv + 1, argc - 1);
	if (!stack_a)
		return (0);
	return (0);
}
