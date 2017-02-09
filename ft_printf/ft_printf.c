/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 22:49:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_args	g_get_args[] =
{
	ft_get_s_arg, ft_get_ls_arg, ft_get_p_arg, ft_get_d_arg,
	ft_get_ld_arg, ft_get_i_arg, ft_get_o_arg, ft_get_lo_arg,
	ft_get_u_arg, ft_get_lu_arg, ft_get_x_arg, ft_get_lx_arg,
	ft_get_c_arg, ft_get_lc_arg, ft_get_b_arg, ft_get_n_arg,
};

t_list	*ft_get_argslist(t_datas **datas, char *buff)
{
	t_list	*tmp;
	size_t	conv_index;
	size_t	i;
	int j = 0;
	size_t	o;

	i = -1;
	tmp = (*datas)->tmp_args;
	tmp->next = (*datas)->tmp_args;
	while (buff[++i] && tmp && tmp->next)
	{
		o = -1;
		conv_index = 0;
		if (buff[i] == '%')
		{
			conv_index = ft_strcspn(buff + i, CONVS);
			while (++o < conv_index)
				;
			if (!(tmp = g_get_args[o](*datas)))
				return (NULL);
			ft_putendl(tmp->content);
			tmp = tmp->next;
			ft_putintendl(j++, 10, BASEUP);
			i += conv_index;
		}
	}	
	return ((*datas)->tmp_args);
}

void	ft_datas_init(t_datas *datas, char *buff)
{
	datas->result = NULL;
	if (!(datas->tmp_args = ft_get_argslist(&datas, buff)))
		return ;
	datas->args = datas->tmp_args;
	datas->flags = NULL;
	datas->len = 0;
}

void	ft_datas_delete(t_datas *datas)
{
	ft_lstdel(&datas->tmp_args);
	ft_strdel(&(datas->result));
	va_end(datas->ap);
}

int		ft_printf(const char *buff, ...)
{
	t_datas	datas;

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
		va_start(datas.ap, buff);
		ft_datas_init(&datas, (char *)buff);
		if (!(datas.args))
			return (-1);
		if (!(datas.result = ft_fill_buff(&datas, (char*)buff)))
			return (-1);
//		ft_datas_delete(&datas);
	}
	datas.len = ft_strlen(datas.result);
	write(1, datas.result, datas.len);
	return (datas.len);
}
