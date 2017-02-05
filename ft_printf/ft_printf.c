/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:57:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/05 20:06:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_buff(t_tools *tools, const char *buff, va_list *ap)
{
	char	*flags;
	char	*tmp;
	size_t	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '%' && buff[i + 1] != '%')
		{
			if (!(tools->result = ft_strdup(buff + (i - 1))))
				return (NULL);
			tools->len += ft_strlen(tools->result);
			if (!(flags = ft_strsub(buff, i, ft_strcspn(buff, CONVS))))
				return (NULL);
			ft_strdel(&flags);
			i++;
		}
		else if (buff[i] == '%' && buff[i + 1] == '%')
			i += 2;
		else 
			i++;
	}
	return (tools->result);
}

int		ft_printf(const char *buff, ...)
{
	va_list	ap;
	t_tools	tools;

	va_start(ap, buff);
	if (!(ft_strchr(buff, '%')))
	{	
		if (!(tools.result = ft_strdup((char*)buff)))
			return (-1);
	}
	else
	{
		if (!(tools.result = ft_fill_buff(&tools, buff, &ap)))
			return (-1);
	}
	tools.len = ft_strlen(tools.result);
	write(1, tools.result, tools.len);
	ft_strdel(&(tools.result));
	va_end(ap);
	return (tools.len);
}
