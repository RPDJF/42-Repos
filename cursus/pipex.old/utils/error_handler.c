/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exitmsg(char *message, int code)
{
	if (message && *message)
		ft_putendl_fd(message, 2);
	exit(code);
}

void	secure_exit(char *msg, int code)
{
	cleargarbage();
	if (msg && *msg)
		exitmsg(msg, code);
	exit(code);
}
