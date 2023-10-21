/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:08:36 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_inttohex(int n);
void	ft_putchar_count(char c, int *size);
void	ft_putstr_count(char *s, int *size);

#endif