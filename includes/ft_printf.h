/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 18:08:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define CONVS 	"sSpdDioOuUxXcCbn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0-+*$L."

typedef struct	s_datas
{
	char		*result;
	t_list		*args;
	char		*flags;
	int			len;
}				t_datas;

int				ft_printf(const char *buff, ...);
void			ft_datas_init(t_datas *datas, va_list ap, char *buff);
t_list			ft_get_argslist(va_list ap, char *buff);
char			*ft_get_unconvdatas(t_datas *datas, char *buff, size_t i);
char			*ft_fill_buff(t_datas *datas, char *buff);
char			*ft_get_convdatas(t_datas *datas, char *buff);
char			*ft_get_lastdatas(t_datas *datas, char *buff);

// 				get_args array functions
char			*ft_get_s_conv(t_datas *datas, va_list ap);
char			*ft_get_ls_conv(t_datas *datas, va_list ap);
char			*ft_get_p_conv(t_datas *datas, va_list ap);
char			*ft_get_d_conv(t_datas *datas, va_list ap);
char			*ft_get_ld_conv(t_datas *datas, va_list ap);
char			*ft_get_i_conv(t_datas *datas, va_list ap);
char			*ft_get_o_conv(t_datas *datas, va_list ap);
char			*ft_get_lo_conv(t_datas *datas, va_list ap);
char			*ft_get_u_conv(t_datas *datas, va_list ap);
char			*ft_get_lu_conv(t_datas *datas, va_list ap);
char			*ft_get_x_conv(t_datas *datas, va_list ap);
char			*ft_get_lx_conv(t_datas *datas, va_list ap);
char			*ft_get_c_conv(t_datas *datas, va_list ap);
char			*ft_get_lc_conv(t_datas *datas, va_list ap);
char			*ft_get_b_conv(t_datas *datas, va_list ap);
char			*ft_get_n_conv(t_datas *datas, va_list ap);

//				convdatas array functions
char			*ft_s_conv(t_datas *datas);
char			*ft_ls_conv(t_datas *datas);
char			*ft_p_conv(t_datas *datas);
char			*ft_d_conv(t_datas *datas);
char			*ft_ld_conv(t_datas *datas);
char			*ft_i_conv(t_datas *datas);
char			*ft_o_conv(t_datas *datas);
char			*ft_lo_conv(t_datas *datas);
char			*ft_u_conv(t_datas *datas);
char			*ft_lu_conv(t_datas *datas);
char			*ft_x_conv(t_datas *datas);
char			*ft_lx_conv(t_datas *datas);
char			*ft_c_conv(t_datas *datas);
char			*ft_lc_conv(t_datas *datas);
char			*ft_b_conv(t_datas *datas);
char			*ft_n_conv(t_datas *datas);

typedef	char	*(*t_dataconv)(t_datas *datas);

typedef t_list	*(*t_getargs)(t_datas *datas, va_list ap);

#endif
