/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:31:11 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/08 22:31:11 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"

typedef struct s_stacks{
	t_list	*a;
	t_list	*b;
	int		size;
	int		size_a;
	int		size_b;
	t_list	*most_a;
	t_list	*least_a;
	t_list	*most_b;
	t_list	*least_b;
	t_list	*last_a;
	t_list	*last_b;
}				t_stacks;

//		FROM utils_bonus/checkers.c

//	check if stack is ordered
int		check_stackorder(t_stacks stacks, char *src);
//	check for duplicates
int		check_duplicates(t_list *head);
//	check if inputs are valid
int		check_input(char **args, size_t size);
//		FROM utils_bonus/error_handler

//	Send message in stderror and exit programm
void	senderror(char *message);
//	Clear stacks before exiting programm with error
void	secure_exit(t_stacks *stacks, char *msg);

//		FROM utils_bonus/handler.c

//	handle operation
void	handler(char *operation, t_stacks *stacks);

//		FROM utils_bonus/resolver.c

//	get lowest nb form stack
int		getleastnb(t_stacks stacks, char src);
//	get highest nb from stack
int		getmostnb(t_stacks stacks, char src);

//		FROM utils_bonus/stack_utils.c

//	push nb from stack src to stack dst
void	push_stack(t_list **src, t_list **dst);
//  Print stacks in a readable output for debug purpose
//void	print_stacks(t_stacks stacks);

#endif