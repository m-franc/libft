/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:18:42 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 18:08:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_d_conv(t_datas *datas)
{
	int		arg;
	char	*argcvd;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'z'))
		return (ft_get_ld_conv(datas));
	else
	{
		arg = va_arg(datas->ap, int);
		if (ft_strstr(datas->flags, "hh"))
			arg = (char)arg;
		else if (ft_strchr(datas->flags, 'h'))
			arg = (short)arg;
		if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
			return (NULL);
	}
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
