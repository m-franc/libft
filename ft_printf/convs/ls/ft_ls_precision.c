/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:36:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/16 21:55:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ls_precision(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;

	if (flags->precision == -1 || flags->precision >= ft_strlen(*argcvd))
		return (0);
//	while (!(argcvd[0][flags->precision] & 0xF0)
//			|| !(argcvd[0][flags->precision] & 0xE0)
//			|| !(argcvd[0][flags->precision] & 0xC0))
//	while (argcvd[0][flags->precision] & 0x80)
//	{
//		PSTR("LOCTET : ")
//		ft_putbits(&argcvd[0][flags->precision], 1);
//		ENDL
//		flags->precision -= 1;
//	}
//	PSTR("LA PRECISION : ")
//	PNBR(flags->precision)
	if (!(tmp = ft_strsub(*argcvd, 0, flags->precision)))
		return (-1);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}