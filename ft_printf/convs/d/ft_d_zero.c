/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:09:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/23 12:12:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_zero(char **argcvd, t_flags *flags)
{
	if (flags->zero == 0 || flags->padding == 0 || flags->precision >= 0)
		return (0);
	else
	{
		flags->precision = flags->padding;
		if (flags->plus == 1 || flags->space == 1)
			flags->precision -= 1;
		flags->padding = 0;
		return (ft_d_precision(argcvd, flags));
	}
}

int	ft_c_zero(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->zero == 0)
		return (0);
	else
	{
		if (!(tmp = ft_strnew(flags->padding)))
			return (-1);
		nb_o = 0;
		while (nb_o < (int)(flags->padding - (ft_strlen(*argcvd))))
			tmp[nb_o++] = '0';
		tmp = ft_strcat(tmp, *argcvd);
		ft_strdel(argcvd);
		*argcvd = tmp;
		return (1);
	}
}
