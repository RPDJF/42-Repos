/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:08:36 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 13:05:28 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libs/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_count(char c, int *size);
void	ft_putstr_count(char *s, int *size);

#endif