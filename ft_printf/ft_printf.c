/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/08 21:21:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		datas.result = NULL;
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
