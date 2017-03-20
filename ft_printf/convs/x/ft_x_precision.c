/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/20 12:05:24 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->precision == -1 || flags->precision < (int)ft_strlen(*argcvd))
		return (0);
	if (flags->diese == 1)
	{
		flags->precision -= 2;
		if (flags->precision == 0)
			return (0);
	}
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	nb_o = 0;
	while (nb_o < (int)((flags->precision) - ((ft_strlen(*argcvd)))))
		tmp[nb_o++] = '0';
	if (**argcvd == '0')
		tmp = ft_strcat(tmp, *argcvd + 1);
	else
		tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
