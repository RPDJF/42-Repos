/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:56:02 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/22 13:36:04 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

//	Returns an hex memory address (basically 
//joining 0x to ft_itoa_base_unsigned)
char	*ft_inttohex(unsigned long int n)
{
	char	*output;
	char	*itoa_base;

	itoa_base = ft_itoa_base_unsigned(n, "0123456789abcdef");
	output = ft_strjoin("0x", itoa_base);
	free(itoa_base);
	return (output);
}

//	Writes char and increment pointer size
void	ft_putchar_count(char c, int *size)
{
	if (!c)
		return ;
	*size = *size + 1;
	write(1, &c, 1);
}

//	Calls ft_putchar_count for each char in pointer s
//	If s is null, writes "(null)"
void	ft_putstr_count(char *s, int *size)
{
	if (!s)
		return (ft_putstr_count("(null)", size));
	while (*(s++))
		ft_putchar_count(*(s - 1), size);
}
