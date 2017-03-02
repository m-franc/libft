/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:23:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_datas_init(t_datas *datas, char *buff)
{
	datas->result = NULL;
	if (!(datas->tmp_args = ft_get_argslist(datas, buff)))
		return (-1);
	datas->args = datas->tmp_args;
	datas->flags = NULL;
	datas->len = 0;
	datas->cplen = 0;
	return (0);
}

int		ft_launch_process(t_datas *datas, char *buff)
{
	if (ft_datas_init(datas, buff) == -1)
		return (-1);
	if (!(datas->result = ft_fill_buff(datas, (char*)buff)))
		return (-1);
	ft_lstdel(&datas->tmp_args);
	return (0);
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
		if ((ft_launch_process(&datas, (char *)buff)) == -1)
			return (-1);
	}
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	return (datas.len + datas.cplen);
}
