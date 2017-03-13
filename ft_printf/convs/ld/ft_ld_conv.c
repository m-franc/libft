/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/13 18:57:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_ld_flags[] =
{
	ft_d_precision, ft_d_zero, ft_d_plus, ft_d_space, ft_d_padding,
};

long int		ft_n_ld(t_datas *datas, t_flags *flags)
{
	va_list		copy;
	long int	arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, long int);
	va_end(copy);
	return (arg);
}

char			*ft_launch_ld_flags(t_datas *datas)
{
	char		*argcvd;
	int			nb_flags;
	long int	arg;
	t_flags		flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit_conv(datas, argcvd));
	nb_flags = 0;
	if (datas->un_ord == 1)
		arg = ft_n_ld(datas, &flags);
	else
		arg = va_arg(datas->ap, long int);
	if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
		return (ft_exit_conv(datas, argcvd));
	while (nb_flags < 5)
	{
		if ((g_ld_flags[nb_flags++](&argcvd, datas, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char			*ft_get_ld_conv(t_datas *datas)
{
	long int	arg;
	char		*argcvd;

	if (!(argcvd = ft_launch_ld_flags(datas)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
