/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:09:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 18:14:10 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_zero(char **argcvd, t_datas *datas, t_flags *flags)
{
	if (flags->zero == 0 || flags->padding == 0)
		return (0);
	else
	{
		flags->precision = flags->padding;
		flags->padding = 0;
		return (ft_d_precision(argcvd, datas, flags));
	}
}

int	ft_c_zero(char **argcvd, t_datas *datas, t_flags *flags)
{
	if (flags->zero == 0 || flags->padding == 0)
		return (0);
	else
	{
		flags->precision = flags->padding;
		flags->padding = 0;
		return (ft_c_precision(argcvd, datas, flags));
	}
}
