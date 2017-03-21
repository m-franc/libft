/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/21 17:07:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static void	ft_argisneg(char **argcvd, t_flags *flags, int *i, int *n)
//{
//}

int		ft_d_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;
	int		n;

	n = 0;
	if (**argcvd == '0' && flags->precision == 0)
		n = 1;
	else if (flags->precision == -1
			|| flags->precision < (int)ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	if (**argcvd == '-')
		n = 1;	
	if (**argcvd == '-')
		tmp[0] = '-';
	if (**argcvd == '-' && flags->plus == 0 && flags->zero == 1)
		flags->precision -= 1;
	nb_o = n;
	while (nb_o < (int)((flags->precision + n) - ((ft_strlen(*argcvd) - n))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd + n);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
