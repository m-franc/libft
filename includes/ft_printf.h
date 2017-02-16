/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 19:21:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_datas
{
	char		*result;
	va_list		ap;
	t_list		*args;
	t_list		*tmp_args;
	t_list		*stars;
	t_list		*tmp_stars;
	char		*flags;
	int			*tmp_len;
	int			len;
}				t_datas;

# include "printf_convs/s.h"
# include "printf_convs/ls.h"
# include "printf_convs/p.h"
# include "printf_convs/d.h"
# include "printf_convs/ld.h"
# include "printf_convs/i.h"
# include "printf_convs/o.h"
# include "printf_convs/lo.h"
# include "printf_convs/u.h"
# include "printf_convs/lu.h"
# include "printf_convs/x.h"
# include "printf_convs/lx.h"
# include "printf_convs/c.h"
# include "printf_convs/lc.h"
# include "printf_convs/b.h"
# include "printf_convs/n.h"
# include "printf_convs/percent.h"
# include "printf_convs/star.h"

# define CONVS 	"sSpdDioOuUxXcCbn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0123456789 -+*$L.hlhhlljz"

int				ft_printf(const char *buff, ...);
int				ft_datas_init(t_datas *datas, char *buff);
int				ft_launch_process(t_datas *datas, char *buff);
t_list			*ft_get_argslist(t_datas *datas, char *buff);
t_list			*ft_get_arg(t_datas *datas, char *buff, size_t *ci);
char			*ft_get_unconvdatas(t_datas *datas, char *buff, size_t i);
char			*ft_fill_buff(t_datas *datas, char *buff);
char			*ft_get_convdatas(t_datas *datas, char *buff);
char			*ft_get_lastdatas(t_datas *datas, char *buff);

typedef	char	*(*t_get_convs)(t_datas *datas);

typedef t_list	*(*t_get_args)(t_datas *datas);

#endif
