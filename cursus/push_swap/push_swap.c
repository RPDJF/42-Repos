/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 15:35:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	secure_exit(t_list **a, t_list **b, char *msg)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
	if (msg && *msg)
		senderror(msg);
	exit(0);
}

static t_list	*parse_args(char **args, size_t size)
{
	char	**tab;
	size_t	i;
	t_list	*head;
	t_list	*new;

	i = 0;
	head = 0;
	while (i++ < size)
	{
		tab = ft_split(args[i - 1], ' ');
		new = arg2stack(tab);
		if (!new)
		{
			ft_lstclear(&head, free);
			free2dmalloc((void **)tab, ft_countwords(args[i - 1], ' '));
			return (0);
		}
		ft_lstadd_back(&head, new);
		free2dmalloc((void **)tab, ft_countwords(args[i - 1], ' '));
	}
	return (head);
}

t_stacks	*new_stacks(t_list *a, t_list *b)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->a = a;
	stacks->b = b;
	stacks->size_a = ft_lstsize(a);
	stacks->size_b = 0;
	stacks->size = stacks->size_a + stacks->size_b;
	stacks->last_a = ft_lstlast(a);
	stacks->last_b = 0;
	stacks->most_a = ft_lstget(stacks->a, getmostnb(*stacks, 'a'));
	stacks->least_a = ft_lstget(stacks->a, getleastnb(*stacks, 'a'));
	stacks->most_b = 0;
	stacks->least_b = 0;
	return (stacks);
}

// need to check for duplicas
int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_list		*a;
	t_list		*b;

	a = 0;
	b = 0;
	if (argc < 2)
		senderror(0);
	if (!check_input(argv + 1, argc - 1))
		secure_exit(&a, &b, "Error");
	a = parse_args(argv + 1, argc - 1);
	if (!a || !check_duplicates(a))
		secure_exit(&a, &b, "Error");
	b = 0;
	stacks = new_stacks(a, b);
	if (!stacks)
		secure_exit(&a, &b, "Error");
	if (!check_stackorder(*stacks, "a"))
		sort(stacks);
	free(stacks);
	secure_exit(&a, &b, 0);
}
