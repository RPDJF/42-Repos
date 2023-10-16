/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:17 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/16 22:31:02 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

const int	BUFFER_SIZE = 4;

/*
* The strncat() function appends not more than n characters from s2, and then
* adds a terminating `\0'.
* The source and destination strings should not overlap, as the behavior is
* undefined.
* The strncat() function returns the pointer s1.
*/
char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while ((unsigned int)j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*data;
	char	*buffer;
	size_t	buffer_count;
	ssize_t	read_buffersize;
	size_t	length;

	data = (char *)malloc(sizeof(char));
	if (!data)
		return (0);
	*data = 0;
	buffer = 0;
	buffer_count = 0;
	read_buffersize = BUFFER_SIZE;
	while (!buffer_count++ || read_buffersize >= BUFFER_SIZE)
	{
		free(buffer);
		buffer = (char *)malloc((read_buffersize + 1) * sizeof(char));
		if (!buffer)
			return (0);
		read_buffersize = read(fd, buffer, BUFFER_SIZE);
		*(buffer + read_buffersize) = 0;
		length = ft_strlen(data) + ft_strlen(buffer);
		if (ft_strchr(buffer, '\n'))
		{
			length = (size_t)ft_strchr(buffer, '\n') - (size_t)buffer;
			length += ft_strlen(data);
			data = ft_exallocf(data, ft_strlen(data) * sizeof(char), (length + 1) * sizeof(char));
			if (!data)
				return (0);
			printf("Buffer:\t%s\n", buffer);
			ft_strncat(data, buffer, length - ft_strlen(data) + 1);
			printf("Data:\t%s\n", data);
			free(buffer);
			break ;
		}
		data = ft_exallocf(data, ft_strlen(data) * sizeof(char), (length + 1) * sizeof(char));
		ft_strncat(data, buffer, BUFFER_SIZE);
	}
	return (data);
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
