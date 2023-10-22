/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:56:55 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/22 13:14:40 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%s\n", "-42");
	printf("%x\n", -42);
	ft_printf("%x\n", -42);
	ft_putendl_fd("", 1);
	printf("%s\n", "-1");
	printf("%x\n", -1);
	ft_printf("%x\n", -1);
	ft_putendl_fd("", 1);
	printf("%s\n", "-4278");
	printf("%x\n", -4278);
	ft_printf("%x\n", -4278);
	ft_putendl_fd("", 1);
	return (0);
}
