/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:08:36 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/23 14:30:53 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

//	Print a formatted string to stdout with a variable number of arguments
int		ft_printf(const char *format, ...);
//	Converts an integer to a hexadecimal string
void	ft_inttohex(unsigned long int n, int *size);
//	Prints a character and increments the size counter
void	ft_putchar_count(char c, int *size);
//	Prints a string and increments the size counter
void	ft_putstr_count(char *s, int *size);
//	Prints a number in a given base and increments the size counter
void	ft_putnbr_count(int n, char *base, int *size);
//	Prints a unsigned long int in a given base and increments the size counter
void	ft_putunnbr_count(unsigned long int n, char *base, int *size);

#endif