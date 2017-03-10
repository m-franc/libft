/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 11:50:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_ld_conv(t_datas *datas)
{

	long int	arg;
	char		*argcvd;

	arg = va_arg(datas->ap, long int);
	if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
