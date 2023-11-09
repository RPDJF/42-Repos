/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:39 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:51 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "betterft.h"

//	Get a static garbage collector
//	Returns NULL if allocation fails
t_list	**getgarbage(void);
//	Free address and removes it from garbage
//	Returns -1 on error
int		*gfree(void *address);
//	Add a pointer to the garbage collector
//	Use it only when mallocating with non-betterft functions
//	betterft functions only uses gallog allocations
//	Returns address
void	*addgarbage(void *address);
//	Returns a null filled galloc
//	Allocation address is added to garbage
void	*gallog(size_t size);
//	Free all lists and all of their contents from garbage
void	cleargarbage(void);
#endif