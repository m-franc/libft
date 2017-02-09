/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:02:20 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 13:58:23 by mfranc           ###   ########.fr       */
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

char	*ft_get_lastdatas(t_datas *datas, char *buff)
{
	char	*lastchars;

	lastchars = datas->result;
	if (!(datas->result = ft_strjoin(datas->result, buff)))
		return (NULL);
	datas->len += ft_strlen(buff);
	ft_strdel(&lastchars);
	return (datas->result);
}

char	*ft_get_convdatas(t_datas *datas, char *buff)
{
	size_t	i;
	size_t	conv_index;
	char	*lastdatas;

	conv_index = ft_strcspn(buff, CONVS);
	if (buff[conv_index] == '\0')
		return (NULL);
	if (!(datas->flags = ft_strsub(buff, 0, conv_index + 1)))
		return (NULL);
	i = 0;
	while (CONVS && CONVS[i] != datas->flags[ft_strlen(datas->flags) - 1])
		i++;
	lastdatas = datas->result;
	if (!(datas->result = g_convdatas[i](datas)))
		return (NULL);
	ft_strdel(&lastdatas);
	return (datas->result);
}

char	*ft_get_unconvdatas(t_datas *datas, char *buff, size_t o)
{
	char	*ucvchar;
	char	*lastdatas;

	if (!(ucvchar = ft_strsub(buff, o, (ft_strlenuntil(buff + o, '%')))))
		return (NULL);
	if (!datas->result)
	{
		lastdatas = NULL;
		datas->len += ft_strlen(ucvchar);
		return (ucvchar);
	}
	else
	{
		lastdatas = datas->result;
		if (!(datas->result = ft_strjoin(datas->result, ucvchar)))
			return (NULL);
		datas->len += ft_strlen(ucvchar);
		ft_strdel(&ucvchar);
		ft_strdel(&lastdatas);
		return (datas->result);
	}
}

char	*ft_fill_buff(t_datas *datas, char *buff)
{
	size_t	i;
	size_t	o;

	i = -1;
	o = 0;
	while (buff[++i])
	{
		if (buff[i] == '%' && buff[i + 1] != '\0')
		{
			if (!(datas->result = ft_get_unconvdatas(datas, buff, o)))
				return (NULL);
			if (!(datas->result = ft_get_convdatas(datas, buff + ((i++) + 1))))
				return (NULL);
			i += ft_strlen(datas->flags);
			o = i;
			ft_strdel(&(datas->flags));
		}
		else if (!(ft_strchr(buff + i, '%')))
		{
			if (!(datas->result = ft_get_lastdatas(datas, buff + (i - 1))))
				return (NULL);
			break ;
		}
	}
	return (datas->result);
}
