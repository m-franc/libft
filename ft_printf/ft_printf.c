/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/08 17:48:03 by mfranc           ###   ########.fr       */
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
	char	*foctets;
	char	*majbuf;

	if (!(foctets = ft_strsub(buff, o, ft_strlenuntil(buff, '%'))))
		return (NULL);
	if (!datas->result)
	{
		datas->len += ft_strlen(foctets);
		return (foctets);
	}
	else
	{
		if (!(majbuf = ft_strjoin(datas->result, foctets)))
			return (NULL);
		ft_strdel(&datas->result);
		datas->result = foctets;
		return (datas->result);
	}
}

char	*ft_fill_buff(t_datas *datas, char *buff)
{
	char	*tmp;
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	datas->result = NULL;
	while (buff[i])
	{
		if (buff[i] == '%' && buff[i + 1] != '\0')
		{
			if (!(datas->result = ft_get_unconvdatas(datas, buff, o)))
				return (NULL);
			if (!(datas->result = ft_get_convdatas(datas, buff + (i + 1))))
				return (NULL);
			o = ft_strlen(datas->flags) + (i++);
			ft_strdel(&(datas->flags));
		}
		i++;
	}
	return (datas->result);
}

int		ft_printf(const char *buff, ...)
{
	t_datas	datas;

	if (!(ft_strchr(buff, '%')))
	{
		if (!(datas.result = ft_strdup((char*)buff)))
			return (-1);
	}
	else
	{
		va_start(datas.args, buff);
		if (!(datas.result = ft_fill_buff(&datas, (char*)buff)))
			return (-1);
		va_end(datas.args);
	}
	datas.len = ft_strlen(datas.result);
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	return (datas.len);
}
