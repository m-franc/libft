/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 17:48:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_exit(t_datas *datas)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	return (NULL);
}

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
	char	*oo;

	va_start(datas.ap, buff);
	if (!(ft_strchr(buff, '%')))
	{
		ft_putstr(buff);
		return (ft_strlen(buff));
	}
	else if (buff[ft_strlen(buff) - 1] == '%')
	{	
		ft_putnstr(buff, (ft_strlen(buff) - 1));
		return (ft_strlen(buff) - 1);
	}
	else
	{
		if ((ft_launch_process(&datas, (char *)buff)) == -1)
			return (-1);
		oo = datas.result;
		write(1, oo, datas.len);
		ft_strdel(&oo);
		return (datas.len + datas.cplen);	
	}
}
