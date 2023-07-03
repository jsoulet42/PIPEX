/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:48:40 by jsoulet           #+#    #+#             */
/*   Updated: 2023/07/03 09:49:43 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}				t_lst;

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *mb, int c, size_t size);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strjoin(const char *s1, const char *s2);

char	**ft_split(char const *s, char c);

t_lst	*ft_lstnew(void *content);

void	ft_lstadd_front(t_lst **lst, t_lst *new);

int		ft_lstsize(t_lst *lst);

t_lst	*ft_lstlast(t_lst *lst);

void	ft_lstadd_back(t_lst **lst, t_lst *new);

void	ft_lstdelone(t_lst *lst, void (*del)(void *));

void	ft_lstclear(t_lst **lst, void (*del)(void *));

void	ft_lstiter(t_lst *lst, void (*f)(void *));

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));

void	free_t2t(char **array);

char	*mall_str_len(char *str);

int		t2t_len(char **array);

char	*get_next_line(int fd);

int		chearch_endline(t_lst *stack);

void	read_stack(int fd, t_lst **stack);

void	go_to_stack(t_lst **stack, char *buffer, int r_read);

t_lst	*lst_getlast(t_lst *stack);

int		ft_strlen2(const char *s);

void	extract_line(t_lst *stack, char **line);

void	generate_line(t_lst *stack, char **line);

void	free_stack(t_lst *stack);

void	clean_stack(t_lst **stack);

int		ft_printf(const char *str, ...);

int		condition(char c, va_list arg);

int		is_condition(char c);

int		mem_add(unsigned long int *num, char *base);

int		ft_nbrbase(int num, char *base);

int		ft_putstr(char *s);

int		ft_putchar(char c);

int		strlenbase(char *base);

int		u_nbr(unsigned int nbr, char *base);

int		printerror(char *msg, int option);

#endif
