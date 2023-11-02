/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:49:45 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/02 18:44:44 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		push_stack(t_list **src, t_list **dst);
int		handler(char *operation, t_list **a, t_list	**b);
int		simple_handler(char *operation, t_list **src, t_list **dst);
void	sort_triple(t_list **a);
int		sort_ten(t_list **a, t_list **b);
int		getleastnb(t_list *stack);
int		check_lstorder(t_list *stack);

#endif