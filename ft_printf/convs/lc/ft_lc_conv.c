/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:21:02 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/11 16:03:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_lc_conv(t_datas *datas)
{
	wint_t	arg;
	char	*argcvd;

	arg = va_arg(datas->ap, wint_t);
	if (arg == 0)
	{
		datas->cplen = datas->len + datas->cplen + 1;
		write(1, datas->result, datas->len);
		write(1, "\0", 1);
		datas->len = 0;
		if (!(datas->result = ft_strnew(0)))
			return (ft_exit(datas));
		return (datas->result);
	}
	else
	{
		if (!(argcvd = ft_wctoa(arg)))
			return (NULL);
		if (!(datas->result = ft_strjoin(datas->result, argcvd)))
			return (NULL);
		datas->len += ft_strlen(argcvd);
		ft_strdel(&argcvd);
		return (datas->result);
	}
}
