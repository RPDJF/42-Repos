/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:49:45 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/07 19:50:54 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stacks{
	t_list	*a;
	t_list	*b;
	int		size;
	int		size_a;
	int		size_b;
}				t_stacks;

//FUNCTIONS PROTOTYPE

//		FROM checkers.c

//	Check if it's on good order
//	Returns 1 if ok
int		check_stackorder(t_stacks stacks, char *src);
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
int		handler(char *operation, t_stacks *stacks, int isheap);

//		FROM resolver.c

//	Get the node id for the lowest value from stack
int		getleastnb(t_list *stack, int size);
//	Get the node id for the highest value from stack
int		getmostnb(t_list *stack, int size);
//	Get the node id for the nearest content from node int* content
//  Returns -1 on error
int		getnear(t_list *stack, int size, t_list node);

//		FROM sorter.c

//	Sort stack A
void	sort(t_stacks *stacks);

//		FROM stack_utils

//	Take the first int of src stack and gives it to dst stack
void	push_stack(t_list **src, t_list **dst);
//	Rotate until specific idx
void	go_to(t_stacks *stacks, char *src, int idx);
//	Simulates a go_to and returns the cost as int
int		sim_go_to(t_stacks *stacks, char *src, int idx);
//	Converts an array of strings into stack
t_list	*arg2stack(char **tab);
//  Print stacks in a readable output
void	print_stacks(t_stacks stacks);

#endif