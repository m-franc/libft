/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/08 17:35:19 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include 		<stdarg.h>
# include 		"libft.h"

# define CONVS 	"sSpdDioOuUxXcCbn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0-+*$L."

typedef struct	s_datas
{
	char		*result;
	va_list		args;
	char		*flags;
	int			len;
	int			uop;
}				t_datas;

int				ft_printf(const char *buff, ...);
char			*ft_fill_buff(t_datas *datas, char *buff);
char			*ft_get_unconvdatas(t_datas *datas, char *buff, size_t o);
char			*ft_get_convdatas(t_datas *datas, char *buff);
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

typedef	char	*(*t_get_dataconv)(t_datas *datas);

#endif
