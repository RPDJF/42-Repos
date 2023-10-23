/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:01:00 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/15 12:12:21 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, char *base, int fd)
{
	unsigned int	un;
	size_t		baselen;

	un = n;
	if (n < 0)
		un = -n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	baselen = ft_strlen(base);
	if (ft_isdigit(un + '0'))
		ft_putchar_fd(base[un - 1], fd);
	else if (un >= baselen)
	{
		ft_putnbr_base(un / baselen, base, fd);
		ft_putnbr_base(un % baselen, base, fd);
	}
}
