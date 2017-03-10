/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:29:14 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 18:07:19 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_x_conv(t_datas *datas)
{
	unsigned long int	arg;
	char				*argcvd;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'z'))
		arg = va_arg(datas->ap, unsigned long int);
	else
	{
		arg = va_arg(datas->ap, unsigned int);
		arg = (unsigned int)arg;
		if (ft_strstr(datas->flags, "hh"))
			arg = (unsigned char)arg;
		else if (ft_strchr(datas->flags, 'h'))
			arg = (unsigned short)arg;
	}
	if (!(argcvd = ft_uitoa(arg, 16, BASELW)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
