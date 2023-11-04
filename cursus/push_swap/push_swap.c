/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:36:24 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/03 17:54:00 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// need free 2d array for prtect
static t_list	*tab2list(char **tab)
{
	t_list	*head;
	int		*content;

	head = 0;
	while (tab && *tab)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_lstclear(&head, free);
		if (!content)
			return (0);
		*content = ft_atoi(*tab);
		head = ft_lstadd(head, content);
		tab++;
	}
	return (head);
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
		new = tab2list(tab);
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

//	Returns 1 if valid is input
//	Else return 0
//	Input is valid if only contains spaces and numericals
int	check_input(char **args, size_t size)
{
	size_t			strsize;

	while (size-- > 0)
	{
		strsize = ft_strlen(args[size]);
		while (strsize-- > 0)
			if (!ft_isdigit(args[size][strsize]))
				if (args[size][strsize] != ' ')
					if (!(args[size][strsize] == '-'
						&& ft_isdigit(args[size][strsize + 1])))
						return (0);
	}
	return (1);
}

//	Returns 1 if no duplicates found
//	Else return 0
static int	check_duplicates(t_list *head)
{
	t_list	*next;

	if (!head)
		return (0);
	next = head->next;
	while (next)
	{
		if (*((int *)(head->content)) == *((int *)(next->content)))
			return (0);
		next = next->next;
	}
	if (head->next)
		return (check_duplicates(head->next));
	return (1);
}

// need to check for duplicas
int	main(int argc, char **argv)
{
	int		lstsize;
	t_list	*a;
	t_list	*b;

	if (!check_input(argv + 1, argc - 1))
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	a = parse_args(argv + 1, argc - 1);
	if (!check_duplicates(a))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	b = 0;
	lstsize = ft_lstsize(a);
	if (lstsize == 3)
		sort_triple(&a);
	else if (lstsize <= 10)
		sort_ten(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}