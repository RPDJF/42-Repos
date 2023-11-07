/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/07 13:59:10 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_list **src, t_list **dst)
{
	t_list	*swap;

	swap = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = swap;
}

void	go_to(t_list **stack, char *src, int size, int idx)
{
	int	i;

	i = 0;
	if (idx > (size / 2))
		i = size - idx;
	while (idx > (size / 2) && i-- > 0)
		handler(ft_strjoin("rr", src), stack, stack, 1);
	while (!(idx > (size / 2)) && i++ < idx)
		handler(ft_strjoin("r", src), stack, stack, 1);
}

int	sim_go_to(int stack_size, int idx)
{
	int	i;
	int	cost;

	cost = 0;
	i = 0;
	if (idx > (stack_size / 2))
		i = stack_size - idx;
	while (idx > (stack_size / 2) && i-- > 0)
		cost++;
	while (!(idx > (stack_size / 2)) && i++ < idx)
		cost++;
	return (cost);
}

t_list	*arg2stack(char **tab)
{
	t_list	*head;
	int		*content;
	char	*itoa;

	head = 0;
	while (tab && *tab)
	{
		content = (int *)malloc(2 * sizeof(int));
		if (!content)
			return (0);
		*content = ft_atoi(*tab);
		itoa = ft_itoa(*content);
		if (ft_strncmp(*tab, itoa, ft_strlen(*tab)))
		{
			free(content);
			free(itoa);
			return (0);
		}
		free(itoa);
		head = ft_lstadd(head, content);
		if (!head)
			return (0);
		tab++;
	}
	return (head);
}

void	print_stacks(t_list *a, t_list *b)
{
	if (a)
		ft_printf("%d", *((int *)a->content));
	if (a)
		a = a->next;
	if (b)
		ft_printf("\t%d", *((int *)b->content));
	if (b)
		b = b->next;
	ft_printf("\n");
	if (!b && !a)
		ft_printf("_\t_\na\tb\n\n");
	if (a || b)
		print_stacks(a, b);
}
