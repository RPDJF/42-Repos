/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:30:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/05 18:08:05 by rude-jes         ###   ########.fr       */
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

void go_to(t_list **a, t_list **b, char src, int idx)
{
    int i = 0;
    int size;
	
	size = ft_lstsize(*a);
	if (src == 'b')
		size = ft_lstsize(*b);
    if (idx >= 0 && idx < size)
    {
        if (idx > (size / 2))
        {
            i = size - idx;
            while (i-- > 0)
            {
                if (src == 'a')
                    handler("rra", a, b);
                else
                    handler("rrb", a, b);
            }
        }
        else
        {
            while (i++ < idx)
            {
                if (src == 'a')
                    handler("ra", a, b);
                else
                    handler("rb", a, b);
            }
        }
    }
}


t_list	*arg2stack(char **tab)
{
	t_list	*head;
	int		*content;
	char	*itoa;

	head = 0;
	while (tab && *tab)
	{
		content = (int *)malloc(sizeof(int));
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
