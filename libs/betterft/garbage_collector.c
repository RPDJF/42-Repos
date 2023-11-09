/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:13 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 18:25:10 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

t_list	**getgarbage(void)
{
	static t_list	**collector;

	if (!collector)
	{
		collector = (t_list **)malloc(sizeof(t_list *));
		*collector = 0;
	}
	return (collector);
}

int	gfree(void *address)
{
	t_list	**head;
	t_list	**read;
	t_list	*todel;

	head = getgarbage();
	if (!head)
	{
		free(address);
		return (0);
	}
	read = head;
	todel = (*read)->next;
	while (todel && *read && todel->content != address)
	{
		*read = (*read)->next;
		todel = todel->next;
	}
	if (!*read || !todel)
	{
		free(address);
		return (0);
	}
	(*read)->next = todel->next;
	free(todel);
	return (-1);
}

void	*addgarbage(void *address)
{
	t_list	**collector;
	t_list	*tmp;

	if (!address)
		return (0);
	collector = getgarbage();
	tmp = ft_lstnew(address);
	tmp->next = 0;
	if (!tmp)
		return (0);
	ft_lstadd_back(collector, tmp);
	return (tmp->content);
}

void	*galloc(size_t size)
{
	return (addgarbage(malloc(size)));
}

void	cleargarbage(void)
{
	ft_lstclear(getgarbage(), free);
	free(getgarbage());
}
