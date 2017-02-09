/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:58:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 13:59:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_dataconv	g_convdatas[] =
{
	ft_get_s_conv, ft_get_ls_conv, ft_get_p_conv, ft_get_d_conv,
	ft_get_ld_conv, ft_get_i_conv, ft_get_o_conv, ft_get_lo_conv,
	ft_get_u_conv, ft_get_lu_conv, ft_get_x_conv, ft_get_lx_conv,
	ft_get_c_conv, ft_get_lc_conv, ft_get_b_conv, ft_get_n_conv
};
