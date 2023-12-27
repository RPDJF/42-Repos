/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:13 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/27 16:23:22 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"
#include "../pipex_bonus.h"

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
	t_list	*read;
	t_list	*todel;

	head = getgarbage();
	if (!head)
	{
		free(address);
		return (-1);
	}
	read = *head;
	todel = read->next;
	while (todel && read && todel->content != address)
	{
		read = read->next;
		todel = todel->next;
	}
	if (!read || !todel)
	{
		free(address);
		return (-1);
	}
	read->next = todel->next;
	ft_lstdelone(todel, free);
	return (0);
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
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		exitmsg(ERR_ALLOC);
	alloc = addgarbage(alloc);
	if (!alloc)
		exitmsg(ERR_ALLOC);
	return (alloc);
}

void	cleargarbage(void)
{
	ft_lstclear(getgarbage(), free);
	free(getgarbage());
}
