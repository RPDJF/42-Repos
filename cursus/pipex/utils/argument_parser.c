/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/29 14:37:55 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	*rallocf(void *ptr, size_t size, size_t newsize, size_t bytes)
{
	void	*p;
	void	*p_p;

	p = galloc(newsize * bytes);
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
	return (p);
}

static void	print_arg(bool *newword, size_t *i, char *strwords, char ***args)
{
	if (*newword)
	{
		*args = rallocf(*args, *i, *i + 2, sizeof(char *));
		(*i)++;
		*newword = false;
	}
	if (!(*args)[*i - 1])
		(*args)[*i - 1] = ft_calloc(1, sizeof(char));
	(*args)[*i - 1] = rallocf((*args)[*i - 1], ft_strlen((*args)[*i - 1]),
			ft_strlen((*args)[*i - 1]) + 1, sizeof(char *));
	(*args)[*i - 1][ft_strlen((*args)[*i - 1])] = *strwords;
}

char	**parse_arg(char *strwords)
{
	char	**args;
	bool	newword;
	char	quote;
	size_t	i;

	args = 0;
	newword = true;
	quote = 0;
	i = 0;
	while (*strwords)
	{
		if (*strwords == ' ' && !quote)
			newword = true;
		else if (!quote && (*strwords == '\'' || *strwords == '\"'))
			quote = *strwords;
		else if (quote && *strwords == quote)
			quote = 0;
		else
			print_arg(&newword, &i, strwords, &args);
		strwords++;
	}
	return (args);
}

char	***fetch_args(t_pipex *pipex, char **argv)
{
	char	***args;
	size_t	argsnb;
	size_t	args_idx;

	argsnb = pipex->nbcommands;
	args = (char ***)ft_calloc(argsnb + 1, sizeof(char **));
	args_idx = 0;
	while (args_idx < argsnb)
	{
		args[args_idx] = parse_arg(argv[args_idx + 2]);
		args_idx++;
	}
	return (args);
}
