/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:53:12 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:53:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_ld_arg(t_datas *datas)
{
	long int	arg;
	char		*argcvd;
	t_list		*new;

	arg = va_arg(datas->ap, long int);
	if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
