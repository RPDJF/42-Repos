/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:56:02 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 14:35:58 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These utils are modified versions of my libft

#include <unistd.h>

void	ft_putchar_count(char c, int *size)
{
	*size = *size + 1;
	write(1, &c, 1);
}

void	ft_putstr_count(char *s, int *size)
{
	while (*(s++))
		ft_putchar_count(*(s - 1), size);
}
