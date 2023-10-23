/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:56:02 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/23 14:50:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_inttohex(unsigned long int n, int *size)
{
	ft_putstr_count("0x", size);
	ft_putunnbr_count(n, "0123456789abcdef", size);
}

void	ft_putchar_count(char c, int *size)
{
	*size = *size + 1;
	if (write(1, &c, 1) < 0)
		*size = -1;
}

void	ft_putstr_count(char *s, int *size)
{
	if (!s)
		return (ft_putstr_count("(null)", size));
	while (*size >= 0 && *(s++))
		ft_putchar_count(*(s - 1), size);
}

void	ft_putnbr_count(int n, char *base, int *size)
{
	unsigned int	un;
	size_t			baselen;

	if (*size < 0)
		return ;
	un = n;
	if (n < 0)
		un = -n;
	if (n < 0)
		ft_putchar_count('-', size);
	if (*size < 0)
		return ;
	baselen = ft_strlen(base);
	if (un < baselen)
		ft_putchar_count(base[un], size);
	else if (un >= baselen)
	{
		ft_putnbr_count(un / baselen, base, size);
		ft_putnbr_count(un % baselen, base, size);
	}
}

void	ft_putunnbr_count(unsigned long int n, char *base, int *size)
{
	unsigned long int	un;
	size_t				baselen;

	if (*size < 0)
		return ;
	un = n;
	baselen = ft_strlen(base);
	if (un < baselen)
		ft_putchar_count(base[un], size);
	else if (un >= baselen)
	{
		ft_putunnbr_count(un / baselen, base, size);
		ft_putunnbr_count(un % baselen, base, size);
	}
}
