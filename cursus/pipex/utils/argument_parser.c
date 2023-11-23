/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/23 18:30:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	*rallocf(void *ptr, size_t size, size_t newsize, size_t bytes)
{
	void	*p;
	void	*p_p;

	p = galloc(newsize * bytes);
	if (!p)
	{
		gfree(ptr);
		return (0);
	}
	p_p = p;
	if (!ptr)
	{
		while ((size_t)p_p++ - (size_t)p < newsize * bytes)
			*((unsigned char *)(p_p - 1)) = 0;
		return (p);
	}
	while ((size_t)p_p - (size_t)p < size * bytes)
	{
		*((unsigned char *)(p_p)) = *((unsigned char *)(ptr + (p_p - p)));
		p_p++;
	}
	while ((size_t)p_p - (size_t)p < newsize * bytes)
		*((unsigned char *)(p_p++)) = 0;
	gfree(ptr);
	return (p);
}

static size_t	tablen(void **tab)
{
	size_t	args_idx;

	if (!tab)
		return (0);
	args_idx = 0;
	while ((tab)[args_idx])
		args_idx++;
	return (args_idx);
}

//	parse args individually (for each command)
static char	**parse_arg(char **words, size_t wordsnb)
{
	char	**args;
	size_t	len;
	size_t	i;

	len = 1;
	i = 0;
	while (i++ < wordsnb)
	{
		if (i - 1 == 0)
			args = ft_split(words[0], ' ');
		else if (words[i - 1][0] == '-')
		{
			args = rallocf(args, len, len + 2, sizeof(char *));
			args[len++] = words[i - 1];
			args[len] = 0;
		}
		else
		{
			if (args[len - 1][0] == '-')
				args[len - 1] = ft_strjoin(args[len - 1],
						ft_strjoin(" ", words[i - 1]));
			else
			{
				args = rallocf(args, len, len + 2, sizeof(char *));
				args[len++] = words[i - 1];
				args[len] = 0;
			}
		}
	}
	return (args);
}

char	***fetch_args(t_pipex *pipex, char **argv)
{
	char	***args;
	char	**words;
	size_t	argsnb;
	size_t	args_idx;

	argsnb = pipex->nbcommands;
	args = (char ***)ft_calloc(argsnb + 1, sizeof(char **));
	args_idx = 0;
	while (args_idx < argsnb)
	{
		words = ft_split(argv[args_idx + 2], ' ');
		args[args_idx] = parse_arg(words, tablen((void **)words));
		args_idx++;
	}
	return (args);
}
