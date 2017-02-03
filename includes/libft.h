/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:04:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/03 16:58:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <locale.h>
# include <wchar.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# define BASEUP "0123456789ABCDEF"
# define BASELW "0123456789abcdef"
# define ENDL ft_putchar('\n');
# define ABS(Value) Value < 0 ? -Value : Value
# define PNBR(x, y, z) ft_putint(x, y, z);
# define PSTR(x) ft_putstr(x);
# define INTMIN -2147483648
# define INTMAX 2147483647
# define UINTMAX 4294967295
# define LLMIN -9223372036854775807
# define LLMAX 9223372036854775807
# define ULLMAX 18446744073109551615

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);
size_t				ft_strlenuntil(const char *str, char c);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strspn(const char *s, const char *accept);
size_t				ft_strcspn(const char *s, const char *reject);
long long			ft_atoi(const char *str);
unsigned long long	ft_atoui(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t n);
char				*ft_strjoin(char const *s1, const char *s2);
char				*ft_strtrim(char const *s);
char				*ft_straddchar(char *s, int c);
void				ft_putstr(char const *s);
char				*ft_strrev(char *s);
void				ft_puttab(char **tab);
char				**ft_strsplit(char const *s, char c);
void				ft_putint(long long n, int base, char *baselist);
void				ft_putuint(unsigned long long n, int base, char *baselist);
char				*ft_itoa(long long n, int base, char *baselist);
char				*ft_uitoa(unsigned long long n, int base, char *baselist);
int					ft_ilen(long long n, int base);
int					ft_uilen(unsigned long long n, int base);
char				*ft_ftoa(long double n, int base, char *bl);
char				*ft_convbase(char *str, int old_base, int new_base, char *baselist);
char				*ft_wctoa(wint_t uchar);
void				ft_putnstr(const char *s, size_t n);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char const c, int fd);
void				ft_putstr_fd(char const *c, int fd);
void				ft_putendl_fd(char const *c, int fd);
void				ft_putint_fd(long long n, int fd, int base, char *baselist);
void				ft_putuint_fd(unsigned long long n, int fd, int base, char *baselist);
void				ft_putaddr(const void *value);
void				ft_putbits(const void *s, size_t size);
char				*ft_vtob(const void *c, size_t size);
int					ft_isword(char c);
int					ft_countword(char const *s);
void				**ft_tabnew(size_t n);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_strsplit_tolist(char const *s, char c);
int					ft_sqrt(int nb);
long long 			ft_power(long long nb, int power);
void				ft_putlist(t_list *lst);
size_t				ft_listcount(t_list *lst);

#endif
