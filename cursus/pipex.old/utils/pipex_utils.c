/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:05:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/13 14:25:43 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**strtabaddfront(char **tab, char *str)
{
	size_t	size;

	size = 0;
	while (tab[size])
	{
		ft_printf(">>> %s\n", tab[size]);
		size++;
	}
	ft_printf("%d\n", size);
	tab = ft_exallocf(tab, (size + 1) * sizeof(char *),
			(size + 2) * sizeof(char *));
	if (!tab)
		secure_exit("Fail to allocate memory", 1);
	while (size--)
		tab[size + 1] = tab[size];
	*tab = str;
	return (tab);
}

char	*getfilepath(const char *file)
{
	char	*path;
	char	*pathend;
	size_t	size;

	path = ft_strdup(file);
	if (!path)
		secure_exit("Fail to allocate memory", 1);
	pathend = ft_strrchr(path, '/');
	if (pathend && *pathend)
	{
		*(pathend + 1) = 0;
		size = ft_strlen(path);
		path = ft_exallocf(path, size, size);
	}
	else
		path = ft_strdup("./");
	if (!path)
		secure_exit("Fail to allocate memory", 1);
	return (path);
}
