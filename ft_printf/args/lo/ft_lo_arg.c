/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lo_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:13:36 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:54:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_lo_arg(t_datas *datas)
{
	unsigned long int	arg;
	char			*argcvd;
	t_list			*new;

	arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 8, BASEUP)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
