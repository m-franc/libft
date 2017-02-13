/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/13 17:44:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define CONVS 	"sSpdDioOuUxXcCbn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0123456789 -+*$L.hlhhlljz"

typedef struct	s_datas
{
	char		*result;
	va_list		ap;
	t_list		*args;
	t_list		*tmp_args;
	char		*flags;
	int			len;
}				t_datas;

int				ft_printf(const char *buff, ...);
void			ft_datas_init(t_datas *datas, char *buff);
int				ft_launch_process(t_datas *datas, char *buff);
t_list			*ft_get_argslist(t_datas *datas, char *buff);
t_list			*ft_get_arg(t_datas *datas, char *buff);
char			*ft_get_unconvdatas(t_datas *datas, char *buff, size_t i);
char			*ft_fill_buff(t_datas *datas, char *buff);
char			*ft_get_convdatas(t_datas *datas, char *buff);
char			*ft_get_lastdatas(t_datas *datas, char *buff);

// 				get_args array functions
char			*ft_get_s_conv(t_datas *datas);
char			*ft_get_ls_conv(t_datas *datas);
char			*ft_get_p_conv(t_datas *datas);
char			*ft_get_d_conv(t_datas *datas);
char			*ft_get_ld_conv(t_datas *datas);
char			*ft_get_i_conv(t_datas *datas);
char			*ft_get_o_conv(t_datas *datas);
char			*ft_get_lo_conv(t_datas *datas);
char			*ft_get_u_conv(t_datas *datas);
char			*ft_get_lu_conv(t_datas *datas);
char			*ft_get_x_conv(t_datas *datas);
char			*ft_get_lx_conv(t_datas *datas);
char			*ft_get_c_conv(t_datas *datas);
char			*ft_get_lc_conv(t_datas *datas);
char			*ft_get_b_conv(t_datas *datas);
char			*ft_get_n_conv(t_datas *datas);

//				convdatas array functions
t_list			*ft_get_s_arg(t_datas *datas);
t_list			*ft_get_ls_arg(t_datas *datas);
t_list			*ft_get_p_arg(t_datas *datas);
t_list			*ft_get_d_arg(t_datas *datas);
t_list			*ft_get_ld_arg(t_datas *datas);
t_list			*ft_get_i_arg(t_datas *datas);
t_list			*ft_get_o_arg(t_datas *datas);
t_list			*ft_get_lo_arg(t_datas *datas);
t_list			*ft_get_u_arg(t_datas *datas);
t_list			*ft_get_lu_arg(t_datas *datas);
t_list			*ft_get_x_arg(t_datas *datas);
t_list			*ft_get_lx_arg(t_datas *datas);
t_list			*ft_get_c_arg(t_datas *datas);
t_list			*ft_get_lc_arg(t_datas *datas);
t_list			*ft_get_b_arg(t_datas *datas);
t_list			*ft_get_n_arg(t_datas *datas);

typedef	char	*(*t_get_convs)(t_datas *datas);

typedef t_list	*(*t_get_args)(t_datas *datas);

#endif
