/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lu_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 12:23:25 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_lu_conv(t_datas *datas)
{

	unsigned long int	arg;
	char				*argcvd;

	arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
