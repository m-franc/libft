/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/07 21:02:24 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_dataconv	g_convdatas[] =
{
	ft_get_s_conv, ft_get_S_conv, ft_get_p_conv, ft_get_d_conv, ft_get_D_conv,
	ft_get_i_conv, ft_get_o_conv, ft_get_O_conv, ft_get_u_conv, ft_get_U_conv,
	ft_get_x_conv, ft_get_X_conv, ft_get_c_conv, ft_get_C_conv, ft_get_b_conv,
	ft_get_r_conv, ft_get_k_conv, ft_get_e_conv, ft_get_E_conv, ft_get_f_conv,
	ft_get_F_conv, ft_get_g_conv, ft_get_G_conv, ft_get_a_conv, ft_get_A_conv,
	ft_get_n_conv
};

char	*ft_prepareconv(t_datas *datas, char *buff)
{
	size_t	i;
	size_t	conv_index;

	conv_index = ft_strcspn(buff, CONVS);
	if (buff[conv_index] == '\0')
		return (NULL);
	if (!(datas->flags = ft_strsub(buff, 0, conv_index + 1)))
		return (NULL);
	i = 0;
	while (CONVS && CONVS[i] != datas->flags[ft_strlen(datas->flags) - 1])
		i++;
	return (g_convdatas[i - 1](datas));
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
			if (!(datas->result = ft_prepareconv(datas, buff + (i + 1))))
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
		if (!(datas.result = ft_fill_buff(&datas, (char*)buff)))
			return (-1);
	}
	datas.len = ft_strlen(datas.result);
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	return (datas.len);
}
