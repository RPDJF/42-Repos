/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:49 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/27 17:37:08 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*init_heredoc(char *limiter, t_pipex *pipex)
{
	int		fd;
	char	*line;

	fd = open(HEREDOC_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		progcontextmsg(*pipex, HEREDOC_FILENAME, strerror(errno));
	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strlen(limiter) == ft_strlen(line) - 1
			&& !ft_strncmp(line, limiter, ft_strlen(line) - 1))
			break ;
		if (write(fd, line, ft_strlen(line) - 1) < 0 || write(fd, "\n", 1) < 0)
			exitprogmsg(*pipex, strerror(errno));
		line = ft_get_next_line(STDIN_FILENO);
	}
	if (close(fd) < 0)
		exitprogmsg(*pipex, strerror(errno));
	pipex->heredoc = true;
	return (HEREDOC_FILENAME);
}
