/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/07 21:10:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include 		<stdarg.h>
# include 		"libft.h"

# define CONVS 	"sSpdDioOuUxXcCbrkeEfFgGaAn%"
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
char			*ft_prepareconv(t_datas *datas, char *buff);
char			*ft_get_s_conv(t_datas *datas);
char			*ft_get_S_conv(t_datas *datas);
char			*ft_get_p_conv(t_datas *datas);
char			*ft_get_d_conv(t_datas *datas);
char			*ft_get_D_conv(t_datas *datas);
char			*ft_get_i_conv(t_datas *datas);
char			*ft_get_o_conv(t_datas *datas);
char			*ft_get_O_conv(t_datas *datas);
char			*ft_get_u_conv(t_datas *datas);
char			*ft_get_U_conv(t_datas *datas);
char			*ft_get_x_conv(t_datas *datas);
char			*ft_get_X_conv(t_datas *datas);
char			*ft_get_c_conv(t_datas *datas);
char			*ft_get_C_conv(t_datas *datas);
char			*ft_get_b_conv(t_datas *datas);
char			*ft_get_r_conv(t_datas *datas);
char			*ft_get_k_conv(t_datas *datas);
char			*ft_get_e_conv(t_datas *datas);
char			*ft_get_E_conv(t_datas *datas);
char			*ft_get_f_conv(t_datas *datas);
char			*ft_get_F_conv(t_datas *datas);
char			*ft_get_g_conv(t_datas *datas);
char			*ft_get_G_conv(t_datas *datas);
char			*ft_get_a_conv(t_datas *datas);
char			*ft_get_A_conv(t_datas *datas);
char			*ft_get_n_conv(t_datas *datas);

typedef	char	*(*t_get_dataconv)(t_datas *datas);

#endif
