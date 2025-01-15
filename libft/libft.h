/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:02:17 by peda-cos          #+#    #+#             */
/*   Updated: 2025/01/14 19:47:19 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	int				*index;
	struct s_list	*next;
}					t_list;

int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putunbr_fd(unsigned int n, int fd);
int					ft_puthex_fd(unsigned int n, int uppercase, int fd);
int					ft_putptr_fd(unsigned long ptr, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_printf(const char *format, ...);

int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t count, size_t size);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*get_next_line(int fd);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_tolower(int c);
int					ft_toupper(int c);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_min(int a, int b);
int					ft_max(int a, int b);

unsigned int		ft_atoi_base(const char *s_str, char *b_str);
int					ft_isupper(int c);
int					ft_islower(int c);

#endif
