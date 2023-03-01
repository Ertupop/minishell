/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jule-mer <jule-mer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:25:55 by jule-mer          #+#    #+#             */
/*   Updated: 2023/02/08 11:49:07 by jule-mer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa_2(int n, t_list **collector);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystak, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

//get_next_line.c
char	*free_str(char *str);
char	*clear_buf(char *str, char *buf);
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*fdup(char *str);
char	*join(char *str, char *buf);
int		there_is_n(char *buf);
int		strlen_n(char *str);

//ft_print.c
int		ft_printf(const char *print, ...);
int		ft_types(va_list args, char type);
int		ft_print_str(char *str);
int		ft_print_char(char c);

//ft_print_int.c
int		ft_print_hexa_min(unsigned int nb);
int		ft_print_hexa_maj(unsigned int nb);
int		ft_print_int(int nb);
int		ft_print_unsigned_int(unsigned int nb);

//ft_itoa.c
char	*ft_itoa(int n);

//ft_itoa_unsigned.c
char	*ft_itoa_unsigned(unsigned int n);

//ft_void.c
void	ft_putchar(char c);
int		ft_void_len(uintptr_t n);
void	ft_void_hexa(uintptr_t n);
int		ft_print_void(unsigned long long ptr);

//garbage_collector.c
void	gc_dell(t_list *collector);
int		gc_dell_one(t_list *collector, void *addr);
int		*gc_alloc_int(t_list **collector, int size);
char	*gc_alloc_char(t_list **collector, int size);

#endif
