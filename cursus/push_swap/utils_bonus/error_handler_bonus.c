/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 11:42:02 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	senderror(char *message)
{
	if (message && *message)
		ft_putendl_fd(message, 2);
	exit(1);
}

void	secure_exit(t_stacks *stacks, char *msg)
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
