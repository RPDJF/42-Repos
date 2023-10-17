/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/17 18:12:58 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*
*	Search for unsigned char c
*	Returns a pointer to the first occurence of c
*	If c is null, returns a pointer to the end of s
*	If c is not found, return null
*/
char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s)
		return ((char *)s);
	return (0);
}

const int	BUFFER_SIZE = 4;

char	*get_next_line(int fd)
{
	char	*str;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	rbytes;
	size_t	length;

	if (!fd)
		return (0);
	str = 0;
	rbytes = 1;
	while (rbytes)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes <= 0)
			break ;
		buffer[rbytes] = 0;
		length = ft_strlen(str);
		str = ft_exallocf((void **)str, length + 1, length + rbytes + 1);
		if (!str)
			return (0);
		ft_strncat(str, buffer, rbytes);
		if (ft_strchr(str, '\n'))
			str = ft_substrf(str, 0, ft_strchr(str, '\n') - str + 1);
		if (!str)
			return (0);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

#include <stdio.h>
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (1);
	printf("Output:\t%s", get_next_line(fd));
}
