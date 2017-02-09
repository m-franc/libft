/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 18:01:25 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_getargs	g_getargs[] =
{
	ft_get_s_arg, ft_get_ls_arg, ft_get_p_arg, ft_get_d_arg,
	ft_get_ld_arg, ft_get_i_arg, ft_get_o_arg, ft_get_lo_arg,
	ft_get_u_arg, ft_get_lu_arg, ft_get_x_arg, ft_get_lx_arg,
	ft_get_c_arg, ft_get_lc_arg, ft_get_b_arg, ft_get_n_arg,
};

t_list	*ft_get_argslist(va_list ap, char *buff)
{
	t_list	*args;
	t_list	*tmp;
	size_t	conv_index;
	size_t	i;
	size_t	o;

	*args = NULL;
	tmp = args;
	i = -1;
	while (buff[++i])
	{
		o = -1;
		conv_index = 0;
		if (buff[i] == '%')
		{
			conv_index = ft_strcpsn(buff + i, CONVS);
			while (++o < conv_index)
			if (!(tmp = g_get_args[o](datas, ap)))
		}
	}
}

void	ft_data_init(t_datas *datas, va_list ap, char *buff)
{
	datas->result = NULL;
	datas->args = ft_get_argslist(ap, buff);
	datas->flags = NULL;
	datas->len = 0;
}

int		ft_printf(const char *buff, ...)
{
	t_datas	datas;
	va_list	ap;

	if (!(ft_strchr(buff, '%')))
	{
		if (!(datas.result = ft_strdup((char*)buff)))
			return (-1);
	}
	else if (buff[ft_strlen(buff) - 1] == '%')
	{	
		if (!(datas.result = ft_strsub(buff, 0, ft_strlen(buff) - 1)))
			return (-1);
	}
	else
	{
		ft_datas_init(datas, ap, buff);
		va_start(ap, buff);
		if (!(datas.result = ft_fill_buff(&datas, (char*)buff)))
			return (-1);
		va_end(ap);
	}
	datas.len = ft_strlen(datas.result);
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	return (datas.len);
}
