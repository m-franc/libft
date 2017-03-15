/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 18:13:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_precision(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;
	int		nb_o;
	int		neg;

	if (**argcvd == '0' && flags->precision == 0)
		neg = 1;
	else if (flags->precision == -1 || flags->precision < ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	nb_o = 0;
	neg = 0;
	if (**argcvd == '-' || (**argcvd == '0' && flags->precision == 0))
	{
		nb_o = 1;
		neg = 1;
		if (**argcvd == '-')
			tmp[0] = '-';
	}
	while (nb_o < ((flags->precision + neg) - ((ft_strlen(*argcvd) - neg))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd + neg);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}

int		ft_c_precision(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->precision == -1 || flags->precision < ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	nb_o = 0;
	while (nb_o < (flags->precision) - (ft_strlen(*argcvd)))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
