/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/06 20:41:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// this function will get all of charchacter between % character and the conv character
char	*ft_get_flags(t_datas *datas, char *buff)
{
	size_t	conv_index;

	conv_index = ft_strcspn(buff, CONVS);
	if (!(datas->flags = ft_strsub(buff, 0, conv_index)))
		return (NULL);
	conv_index = 0;
	return (datas->flags);
}

// this function will get in result final datas before % character
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

// this function will fill the result final while char* exists
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
			if (!(datas->flags = ft_get_flags(datas, buff + (i + 1))))
				return (NULL);
			//		if (!(datas->result = ft_convdatas(datas, buff)))
			//			return (NULL);
			o = ft_strlen(datas->flags) + (++i);
			ft_strdel(&(datas->flags));
		}
		i++;
	}
	return (datas->result);
}

//this function will lauch the buffer analysis, treat it if it's necessary, and write it
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
	va_start(datas.args, buff);
	datas.len = ft_strlen(datas.result);
	write(1, datas.result, datas.len);
	ft_strdel(&(datas.result));
	va_end(datas.args);
	return (datas.len);
}
