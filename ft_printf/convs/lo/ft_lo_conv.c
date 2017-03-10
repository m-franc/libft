/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lo_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 12:18:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_lo_conv(t_datas *datas)
{

	unsigned long int	arg;
	char				*argcvd;

	arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 8, BASEUP)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
