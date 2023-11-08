/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:51 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	senderror(char *message)
{
	if (message && *message)
		ft_putendl_fd(message, 2);
	exit(1);
}
