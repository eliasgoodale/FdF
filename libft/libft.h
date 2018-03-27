/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:54:52 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/19 16:16:25 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define IS_LOWER(x) (x >= 'a' && x <= 'z' ? 1 : 0)
#define IS_UPPER(x) (x >= 'A' && x <= 'Z' ? 1 : 0)
#define WHITE_S(x) (x == ' ' || x == '\t' || x == '\n' ? 1 : 0)
#define W_PC(x) (x == '\v' || x == '\r' || x == '\f' ? 1 : 0)
#define INT_MIN -2147483648
#define LONG_MAX 9223372036854775807

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int const fd, char **line);
size_t				ft_wordcount(char *s, char c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *str, const char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strncpy(const char *dest, char *src, unsigned int n);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strncat(char *dest, char *src, int nb);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strlowcase(char *str);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *str, int c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_alpha(char *str);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_itoa(int n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_intlen(int n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);

#	endif
