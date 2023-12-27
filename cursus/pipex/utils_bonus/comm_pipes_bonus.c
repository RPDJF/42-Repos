/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_pipes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:51:20 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/27 17:32:34 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	**new_bidirectional_comm(t_pipex *pipex)
{
	int	**comm;

	comm = galloc(sizeof(int *) * 2);
	comm[EVEN_COMM] = galloc(sizeof(int) * 2);
	comm[ODD_COMM] = galloc(sizeof(int) * 2);
	if (pipe(comm[EVEN_COMM]) < 0 || pipe(comm[ODD_COMM]) < 0)
		exitprogmsg(*pipex, strerror(errno));
	return (comm);
}

void	free_bidirectional_comm(int **comm, t_pipex *pipex)
{
	if (close(comm[EVEN_COMM][0]) < 0
		|| close(comm[EVEN_COMM][1]) < 0
		|| close(comm[ODD_COMM][0]) < 0
		|| close(comm[ODD_COMM][1]) < 0)
		exitprogmsg(*pipex, strerror(errno));
	gfree(comm[EVEN_COMM]);
	gfree(comm[ODD_COMM]);
	gfree(comm);
}

void	comm_toggler(int **comm, int nth_child, t_pipex *pipex)
{
	int	current;
	int	old;

	current = nth_child % 2;
	if (current == ODD_COMM)
		old = EVEN_COMM;
	else
		old = ODD_COMM;
	if (close(comm[current][0]) < 0
			|| close(comm[old][1]) < 0
			|| dup2(comm[old][0], STDIN_FILENO) < 0
			|| close(comm[old][0]) < 0
			|| dup2(comm[current][1], STDOUT_FILENO) < 0
			|| close(comm[current][1]) < 0)
		exitprogmsg(*pipex, strerror(errno));
}
