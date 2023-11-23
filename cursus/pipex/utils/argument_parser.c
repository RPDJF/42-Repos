/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/23 14:31:53 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	tablen(void *tab, size_t size)
{
	size_t	args_idx;

	if (!tab)
		return (0);
	args_idx = 0;
	while (((unsigned char *)tab)[args_idx * size])
		args_idx++;
	return (args_idx);
}

//	parse args individually (for each command)
static char	**parse_arg(char **words, size_t wordsnb)
{
	char	**args;
	size_t	len;
	size_t	words_idx;

	wordsnb = tablen(words, sizeof(char *));
	len = 1;
	words_idx = 0;
	args = 0;
	while (words_idx < wordsnb)
	{
		if (words_idx == 0)
			args = ft_split(words[0], ' ');
		else if (words[words_idx][0] == '-')
		{
			args = ft_exallocf(args, len * sizeof(char *),
					(len + 2) * sizeof(char *));
			args[len++] = words[words_idx];
		}
		else
		{
			if (len <= 1)
			{
				args = ft_exallocf(args, len * sizeof(char *),
						(len + 2) * sizeof(char *));
				len++;
			}
			args[len - 1] = ft_strjoin(args[len - 1],
					ft_strjoin(" ", words[words_idx]));
		}
		words_idx++;
	}
	if (args)
		return (ft_exallocf(args, (len + 1) * sizeof(char *),
				(len + 2) * sizeof(char *)));
	return (ft_split(words[0], ' '));
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
		args[args_idx] = parse_arg(words, tablen(words, sizeof(char *)));
		args_idx++;
	}
	return (args);
}
