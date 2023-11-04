/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:49:45 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/04 13:10:40 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//FUNCTIONS PROTOTYPE

//		FROM checkers.c

//	Check if it's on good order
//	Returns 1 if ok
int		check_stackorder(t_list *stack);
//	Returns 1 if no duplicates found
//	Else return 0
int		check_duplicates(t_list *head);
//	Returns 1 if valid is input
//	Else return 0
//	Input is valid if only contains spaces and numericals
int		check_input(char **args, size_t size);

//		FROM error_handler.c

//	Send simple error and exit program
void	senderror(char *message);

//		FROM handler.c

//	Apply operation to stacks
int		handler(char *operation, t_list **a, t_list	**b);

//		FROM sorter.c

//	Sort stack A
void	sort(t_list **a, t_list **b);

//		FROM stack_utils

//	Get the node id for the lowest value from stack
int		getleastnb(t_list *stack);
//	Take the first int of src stack and gives it to dst stack
void	push_stack(t_list **src, t_list **dst);
//	Converts an array of strings into stack
t_list	*arg2stack(char **tab);

#endif