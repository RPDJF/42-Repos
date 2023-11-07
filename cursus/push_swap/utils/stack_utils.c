/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/07 16:46:38 by rude-jes         ###   ########.fr       */
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

void	go_to(t_stacks *stacks, char *src, int idx)
{
	int	i;
	int	size;

	size = stacks->size_a;
	if (*src == 'b')
		size = stacks->size_b;
	i = 0;
	if (idx > (size / 2))
		i = size - idx;
	while (idx > (size / 2) && i-- > 0)
		handler(ft_strjoin("rr", src), stacks, 1);
	while (!(idx > (size / 2)) && i++ < idx)
		handler(ft_strjoin("r", src), stacks, 1);
}

int	sim_go_to(t_stacks *stacks, char *src, int idx)
{
	int	i;
	int	cost;
	int	size;

	size = stacks->size_a;
	if (*src == 'b')
		size = stacks->size_b;
	cost = 0;
	i = 0;
	if (idx > (size / 2))
		i = size - idx;
	while (idx > (size / 2) && i-- > 0)
		cost++;
	while (!(idx > (size / 2)) && i++ < idx)
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

void	print_stacks(t_stacks stacks)
{
	if (stacks.a)
		ft_printf("%d", *((int *)stacks.a->content));
	if (stacks.a)
		stacks.a = stacks.a->next;
	if (stacks.b)
		ft_printf("\t%d", *((int *)stacks.b->content));
	if (stacks.b)
		stacks.b = stacks.b->next;
	ft_printf("\n");
	if (!stacks.b && !stacks.a)
		ft_printf("_\t_\na\tb\n\n");
	if (stacks.a || stacks.b)
		print_stacks(stacks);
}
