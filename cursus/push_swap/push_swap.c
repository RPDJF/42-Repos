/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/29 20:30:21 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_garbage(void *garbage, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
		free(((unsigned char *)garbage)[idx ++]);
}

static int	print_stack(int *stack, size_t size)
{
	int		rslt;
	size_t	idx;

	rslt = 0;
	idx = 0;
	while (idx < size && rslt >= 0)
		rslt = ft_printf("%d\n", stack[idx++]);
	return (rslt);
}

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
	t_garbage_collector	gc;
	int					*stack_a;

	stack_a = parse_args(argv + 1, argc - 1);
	if (!stack_a)
		return (0);
	ft_mempush(gc.collector, 0, stack_a);
	if (print_stack(stack_a, argc - 1) < 0)
		ft_garbage_destroy(gc);
	return (0);
}
