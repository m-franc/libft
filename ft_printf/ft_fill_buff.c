/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:02:20 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 17:56:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_convs	g_get_convs[] =
{
	ft_get_s_conv, ft_get_ls_conv, ft_get_p_conv, ft_get_d_conv,
	ft_get_ld_conv, ft_get_d_conv, ft_get_o_conv, ft_get_lo_conv,
	ft_get_u_conv, ft_get_lu_conv, ft_get_x_conv, ft_get_lx_conv,
	ft_get_w_conv, ft_get_c_conv, ft_get_lc_conv, ft_get_b_conv,
	ft_get_n_conv, ft_get_percent_conv,
};

char	*ft_get_lastdatas(t_datas *datas, char *buff)
{
	char	*lastchars;

	lastchars = datas->result;
	if (!(datas->result = ft_strjoin(datas->result, buff)))
		return (NULL);
	if ((ft_buff_customer(&(datas->result))) == -1)
		return (NULL);
	datas->len = ft_strlen(datas->result);
	ft_strdel(&lastchars);
	return (datas->result);
}

int	ft_no_conv_manager(char *buff,
		t_datas *datas, size_t conv_index)
{
	char	*lastdatas;
	char	*tmpsf;
	t_flags	flags;

	if (datas->result)
		lastdatas = datas->result;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (-1);
	if (!(tmpsf = ft_straddchar(NULL, buff[conv_index + 1])))
		return (-1);
	if (!(tmpsf = ft_launch_c_flags(&tmpsf, datas, &flags)))
		return (-1);
	if (!(datas->result = ft_strjoin(datas->result, tmpsf)))
		return (-1);
	if (datas->result)
		ft_strdel(&lastdatas);
	ft_strdel(&tmpsf);
	return (1);
}

int		ft_get_convdatas(t_datas *datas, char *buff)
{
	size_t	i;
	size_t	conv_index;
	char	*lastdatas;

	lastdatas = datas->result;
	conv_index = ft_strspn(buff + 1, FLAGS);
	if (!(datas->flags = ft_strsub(buff, 1, conv_index)))
		return (-1);
	if (ft_strchr(datas->flags, '$'))
		datas->un_ord = 1;
	if (!ft_strchr(datas->flags, '$') && datas->un_ord == 1)
		return (-1);
	if (buff[conv_index + 1] == '\0')
		return (0);
	if (!(ft_strchr(CONVS, buff[conv_index + 1])))
		return (ft_no_conv_manager(buff, datas, conv_index));
	i = -1;
	while (CONVS && CONVS[++i] != buff[conv_index + 1])
		;
	if (!(datas->result = g_get_convs[i](datas)))
		return (-1);
	ft_last_datasmanager(datas, buff[conv_index + 1], &lastdatas);
	return (1);
}

char	*ft_get_unconvdatas(t_datas *datas, char *buff, size_t o)
{
	char	*ucvchar;
	char	*lastdatas;

	if (!(ucvchar = ft_strsub(buff, o, (ft_strlenuntil(buff + o, '%')))))
		return (NULL);
	if ((ft_buff_customer(&ucvchar)) == -1)
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
				return (ft_exit(datas));
			if ((ft_get_convdatas(datas, (buff + i))) == -1)
				return (ft_exit(datas));
			i += ft_strlen(datas->flags) + 1;
			o = i + 1;
			ft_strdel(&(datas->flags));
		}
		else if ((!(ft_strchr(buff + i, '%')))
			&& i == (ft_strlen(buff) - 1))
		{
			if (!(datas->result = ft_get_lastdatas(datas, buff + i)))
				return (ft_exit(datas));
		}
	}
	return (datas->result);
}
