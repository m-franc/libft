/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lu_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:29:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:31:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_lu_arg(t_datas *datas)
{
	unsigned long int	arg;
	char				*argcvd;
	t_list				*new;

	arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
