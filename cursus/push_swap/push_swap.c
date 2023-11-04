/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/04 15:41:05 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	secure_exit(t_list **a, t_list **b, char *msg)
{
	ft_lstclear(a, free);
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

// need to check for duplicas
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		senderror(0);
	if (!check_input(argv + 1, argc - 1))
		secure_exit(&a, &b, "Error");
	a = parse_args(argv + 1, argc - 1);
	if (!a || !check_duplicates(a))
		secure_exit(&a, &b, "Error");
	b = 0;
	sort(&a, &b);
	secure_exit(&a, &b, 0);
}
