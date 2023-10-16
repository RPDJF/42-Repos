/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/16 17:56:47 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	ssize_t	buffer_size;
	char	*p;
	char	*buffer;
	ssize_t	pos;

	buffer = (char *)malloc(1025 * sizeof(char));
	if (!buffer)
		return (0);
	pos = 0;
	read(fd, buffer, 1024);
	buffer[1024] = 0;
	p = ft_strchr(buffer, '\n');
	if (!p)
		return (0);
	size_t temp;
	temp = p - buffer;
	return (ft_substr(buffer, 0, temp));
}

#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (1);
	printf("%s\n", get_next_line(fd));
}
