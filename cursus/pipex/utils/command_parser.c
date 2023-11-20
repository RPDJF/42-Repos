/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:28 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/20 14:36:23 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char **get_command(char **args, int size)
{
	
}

static char	**parse_command()
{
	
}

char	***parse_commands(int argc, char **argv)
{
	char	***commands;
	int		id;
	int		argpos;

	commands = 0;
	id = 0;
	argpos = 2;

	while (argpos < argc - 2)
	{
		if (argv[argpos][0] != '-')
		{
			commands = ft_exallocf(commands, sizeof(char **) * id,
					sizeof(char **) * (id + 1));
			commands[id] = ft_calloc(i`)
			if (!commands)
				exitprogmsg();
			commands[id][0] = parse_commands(argc, argv);
		}
	}

}