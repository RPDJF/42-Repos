/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:30:44 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 22:30:44 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	secure_exit(t_stacks *stacks, char *msg)
{
	if (stacks->a)
		ft_lstclear(&stacks->a, free);
	if (stacks->b)
		ft_lstclear(&stacks->b, free);
	free(stacks);
	if (msg && *msg)
		senderror(msg);
	exit(0);
}

//	Converts an array of strings like ft_split into linked chains
t_list	*arg2stack(char **tab)
{
	t_list	*head;
	int		*content;
	char	*itoa;

	head = 0;
	while (tab++ && *(tab - 1))
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			return (0);
		*content = ft_atoi(*(tab - 1));
		itoa = ft_itoa(*content);
		if (ft_strncmp(*(tab - 1), itoa, ft_strlen(*(tab - 1))))
		{
			free(content);
			free(itoa);
			ft_lstclear(&head, free);
			return (0);
		}
		free(itoa);
		head = ft_lstadd(head, content);
		if (!head)
			return (0);
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

t_stacks	*new_stacks(t_list *a)
{
	t_stacks	*stacks;

	if (!a)
		return (0);
	stacks = (t_stacks *)ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		ft_lstclear(&a, free);
	if (!stacks)
		return (0);
	stacks->a = a;
	stacks->b = 0;
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
	char		*line;

	if (argc < 2)
		senderror(0);
	if (!check_input(argv + 1, argc - 1))
		senderror("Error");
	stacks = new_stacks(parse_args(argv + 1, argc - 1));
	if (!stacks)
		senderror("Error");
	if (!check_duplicates(stacks->a))
		secure_exit(stacks, "Error");
	line = ft_get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		handler(line, stacks);
		free(line);
		line = ft_get_next_line(0);
	}
	if (!stacks->size_b && !check_stackorder(*stacks, "a"))
		secure_exit(stacks, "Error");
	ft_putendl_fd("OK", 1);
	secure_exit(stacks, 0);
}
