/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:23 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/09 15:23:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < ' ' || c > 126)
		return (0);
	return (1);
}

// do main to try it out
/*#include <stdio.h>
int main()
{
	char c = 127;
	printf("%d", ft_isprint(c));
	return 0;
}
*/