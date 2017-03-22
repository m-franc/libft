/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:34:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/22 15:12:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->precision < 0
		|| flags->precision < (int)ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	nb_o = 0;
	while (nb_o < (int)(flags->precision - (ft_strlen(*argcvd))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
