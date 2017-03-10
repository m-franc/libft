/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 18:54:55 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_launch_process(t_datas *datas, char *buff)
{
	datas->result = NULL;
	datas->flags = NULL;
	datas->un_ord = 0;
	datas->len = 0;
	datas->cplen = 0;
	if (!(datas->result = ft_fill_buff(datas, (char*)buff)))
		return (-1);
	va_end(datas->ap);
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
