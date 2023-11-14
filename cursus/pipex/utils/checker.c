/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:42:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/14 12:58:01 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    check_files(t_pipex pipex)
{
    if (access(pipex.in, R_OK) < 0)
    {
        ft_putstr_fd(pipex.name, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
        ft_putstr_fd(pipex.in, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
        exitmsg(strerror(errno));
    }
    if (access(pipex.out, W_OK) < 0)
    {
        ft_putstr_fd(pipex.name, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
        ft_putstr_fd(pipex.in, STDERR_FILENO);
        ft_putstr_fd(": ", STDERR_FILENO);
        exitmsg(strerror(errno));
    }
}
