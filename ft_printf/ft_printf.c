/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/13 17:54:34 by mfranc           ###   ########.fr       */
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

t_list	*ft_get_arg(t_datas *datas, char *buff)
{
	size_t	conv_index;
	size_t	i;
	t_list	*new;

	i = -1;
	conv_index = ft_strspn(buff, FLAGS);
	if (buff[conv_index] == '\0')
		return (NULL);
	if (!(ft_strchr(CONVS, buff[conv_index])))
		return (NULL);
	while (CONVS && CONVS[++i] != buff[conv_index])
		;
	if (!(new = g_get_args[i](datas)))
		return (NULL);
	return (new);
}

t_list	*ft_get_argslist(t_datas *datas, char *buff)
{
	t_list	*tmp;
	t_list	*new;
	size_t	conv_index;
	size_t	i;

	i = -1;
	while (buff[++i] != '%')
		;
	if (!(tmp = ft_get_arg(datas, buff + (i + 1))))
		return (NULL);
	new = tmp;
	while (buff[++i] && tmp)
	{
		conv_index = 0;
		if (buff[i] == '%')
		{
			if (!(tmp->next = ft_get_arg(datas, buff + (i + 1))))
				return (NULL);
			tmp = tmp->next;
			i += ft_strlen(tmp->content);
		}
	}
	return (new);
}

void	ft_datas_init(t_datas *datas, char *buff)
{
	datas->result = NULL;
	if (!(datas->tmp_args = ft_get_argslist(datas, buff)))
		return ;
	datas->args = datas->tmp_args;
	datas->flags = NULL;
	datas->len = 0;
}

int		ft_launch_process(t_datas *datas, char *buff)
{
	ft_datas_init(datas, buff);
	if (!(datas->args))
		return (-1);
	if (!(datas->result = ft_fill_buff(datas, (char*)buff)))
		return (-1);
	ft_lstdel(&datas->tmp_args);
	return (datas->len);
}

int		ft_printf(const char *buff, ...)
{
	t_datas	datas;

	if (!(ft_strchr(buff, '%')))
	{
		if (!(datas.result = ft_strdup((char*)buff)))
			return (-1);
		datas.len = ft_strlen(datas.result);
	}
	else if (buff[ft_strlen(buff) - 1] == '%')
	{
		if (!(datas.result = ft_strsub(buff, 0, ft_strlen(buff) - 1)))
			return (-1);
		datas.len = ft_strlen(datas.result);
	}
	else
	{
		va_start(datas.ap, buff);
		if (!(datas.len = ft_launch_process(&datas, (char *)buff)))
			return (-1);
	}
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	return (datas.len);
}
