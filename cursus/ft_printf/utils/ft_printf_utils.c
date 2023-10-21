/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:56:02 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:55 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These utils are modified versions of my libft

#include "../ft_printf.h"
#include <unistd.h>

char	*ft_inttohex(int n)
{
	char	*output;
	char	*itoa_base;

	itoa_base = ft_itoa_base(n, "0123456789abcdef");
	output = ft_strjoin("0x", itoa_base);
	free(itoa_base);
	return (output);
}

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
