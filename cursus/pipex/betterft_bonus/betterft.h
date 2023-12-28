/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   betterft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:19:26 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/28 14:56:00 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERFT_H
# define BETTERFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//		GARBAGE COLLECTOR
//	Get a static garbage collector
//	Returns NULL if allocation fails
t_list	**getgarbage(void);
//	Free address and removes it from garbage
//	Returns -1 on error
int		gfree(void *address);
//	Add a pointer to the garbage collector
//	Use it only when mallocating with non-betterft functions
//	betterft functions only uses gallog allocations
//	Returns address
void	*addgarbage(void *address);
//	Returns a null filled galloc
//	Allocation address is added to garbage
void	*galloc(size_t size);
//	Free all lists and all of their contents from garbage
void	cleargarbage(void);

//		REVISITED LIBFT
//	Converts the initial portion of the string str to int representation
int		ft_atoi(const char *str);
//	Fill memory with NULL value
void	ft_bzero(void *s, size_t n);
//	Return a malloc filled with NULL
void	*ft_calloc(size_t count, size_t size);
//	Check if character is alphanumeric character
int		ft_isalnum(int c);
//	Check if character is alphabetic character
int		ft_isalpha(int c);
//	Check if int is is valid character
int		ft_isascii(int c);
//	Check if charact is digit character
int		ft_isdigit(int c);
//	Check if is printable character
int		ft_isprint(int c);
// Check if is space character
int		ft_isspace(char c);
//	Converts unsigned long int number into a string with specific base
char	*ft_itoa_base_un(unsigned long int n, const char *base);
//	Converts int number into a string with specific base
char	*ft_itoa_base(int n, const char *base);
//	Converts unsigned int number into a string
char	*ft_itoa_un(unsigned int n);
//	Converts int number into a string
char	*ft_itoa(int n);
//	Returns a pointer to the first occurence of specific byte in memory s
//	Returns NULL if no occurence
void	*ft_memchr(const void *s, int c, size_t n);
//	Returns difference between memories
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	Fill dest memory with src values until size_t n is reached
//	Overlap isn't supported
void	*ft_memcpy(void *dest, const void *src, size_t n);
//	Fill dest memory with src values until size_t n is reached
//	Overlap is supported
void	*ft_memmove(void *dest, const void *src, size_t n);
//	Fill memory with itn c value
void	*ft_memset(void *s, int c, size_t n);
//	Free mem references and mem itself
void	ft_memsuperclear(void **m, size_t size);
//	Returns the absolute value of int nb
int		ft_nbabsolute(int nb);
//	Returns lowest int value between nb1 and nb2
int		ft_nblowest(int nb1, int nb2);
//	Home made printf
int		ft_printf(const char *format, ...);
//	Write char in specific filedescriptor
void	ft_putchar_fd(char c, int fd);
//	Write eol in specific filedescriptor
void	ft_putendl_fd(char *s, int fd);
//	Write nbr in specific filedescriptor and base
//	Write nbr in specific filedescriptor
void	ft_putnbr_base(int n, char *base, int fd);
//	Write str in specific filedescriptor
void	ft_putstr_fd(char *s, int fd);
//	Split s with specific separator and return them in a NULL Terminated malloc
char	**ft_split(char const *s, char c);
size_t	ft_countwords(char const *s, char c);
//	Search for specific char in string s and returns his address
char	*ft_strchr(const char *s, int c);
//	Returns a malloc containing the string src
char	*ft_strdup(const char *src);
//	Iter function f for each pointer of s
char	ft_striteri(char *s, void (*f)(unsigned int, char *));
//	Join strings in a single string
char	*ft_strjoin(const char *s1, const char *s2);
//	Check the manual nerd
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//	Check the manual nerd
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//	Returns a string's size
size_t	ft_strlen(const char *str);
//	Iter function f for each char in string s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//	Returns difference between strings
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//	Returns a pointer to the needle in haystack
char	*ft_strnstr(const char	*haystack, const char *needle, size_t len);
//	Returns a pointer to the first occurence of c in s, otherwise returns NULL
char	*ft_strrchr(const char *s, int c);
//	Replace a portion of a string with a new one
char	*ft_strreplace(char *src, char *old, char *new);
//	Returns the string without set characters from the start and the end
char	*ft_strtrim(const char *s1, const char *set);
//	Returns a malloc to the string from start to start + len
char	*ft_substr(char const *s, unsigned int start, size_t len);
//	Lower uppercase character
int		ft_tolower(int c);
//	Upper lowercase character
int		ft_toupper(int c);
//	Add content directly to bottom of list
t_list	*ft_lstadd(t_list *lst, void *content);
//	Adds new list at the start of chainedlist
void	ft_lstadd_back(t_list **lst, t_list *new);
//	Adds new list to the end of chainedlist
void	ft_lstadd_front(t_list **lst, t_list *new);
//	Clears list with del function
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
//	Get node from idx
t_list	*ft_lstget(t_list *lst, size_t idx);
//	Get id from node
int		ft_lstgetid(t_list *list, t_list *node);
//	Delete first node
t_list	*ft_lstpop(t_list *lst, void (*del)(void *));
//	Push content to head of list (creates a list)
t_list	*ft_lstpush(t_list *lst, void *content);
//	Apply a reversed list rotation, the last becomes the first
t_list	*ft_lstrevrotate(t_list *lst);
//	Apply a list rotation, the first becomes the last
t_list	*ft_lstrotate(t_list *lst);
//	Swaps the first two lists
t_list	*ft_lstswap(t_list *lst);
/*
 *	Returns a pointer to an extend malloc
 *	Copies bytes from ptr to the returned malloc
 *	ft_exallocf frees the ptr's pointed malloc
 *
 *	Size inputs represents the size of the malloc in bytes
 *	If ptr is null, returns a new 'calloc' with newsize
 *	Returns 0 if allocation failed and free ptr
 */
void	*ft_exallocf(void *ptr, size_t size, size_t newsize);
/*
 *	Returns the next line from a file as a string, containing \\n.
 *	This functions use creates a static from fd, looping this
 *	functions sends each newline from last one, until EOF char.
 */
char	*ft_get_next_line(int fd);
/*
 *	Concatenate src mem to dest mem
 *	Dest needs to have enough space
 *	Returns null if dest pointer is null
 */
void	*ft_memncat(void *dest, size_t start, void *src, size_t nb);
//	Extend mem allocation and add the \0 char at the end
char	*ft_memtostr(void *mem, size_t size);

#endif
