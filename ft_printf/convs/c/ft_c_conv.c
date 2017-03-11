/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:55:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/11 15:52:28 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c_conv(t_datas *datas)
{
	int				arg;

	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_lc_conv(datas));
	arg = va_arg(datas->ap, int);
	if (arg == 0)
	{
		datas->cplen = datas->len + datas->cplen + 1;
		write(1, datas->result, datas->len);
		write(1, "\0", 1);
		datas->len = 0;
		if (!(datas->result = ft_strnew(0)))
			return (NULL);
		return (datas->result);
	}
	else
	{
		if (!(datas->result = ft_straddchar(datas->result, arg)))
			return (NULL);
		datas->len = ft_strlen(datas->result);
		return (datas->result);
	}
}
