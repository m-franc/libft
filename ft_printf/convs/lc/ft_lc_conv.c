/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:55:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 19:43:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_lc_flags[] = 
{
	ft_c_zero, ft_d_padding, ft_c_precision,
};

static char		*ft_launch_lc_flags(char **argcvd, t_datas *datas, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 3)
	{
		if ((g_lc_flags[nb_flags++](argcvd, datas, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

static char		*ft_lc_exist(t_datas *datas, t_flags *flags, int arg)
{
	char		*argcvd;

	if (!(argcvd = ft_wctoa(arg)))
		return (NULL);
	if (!(argcvd = ft_launch_lc_flags(&argcvd, datas, flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len = ft_strlen(datas->result);
	ft_strdel(&argcvd);
	return (datas->result);
}

static char		*ft_lc_dont_exist(t_datas *datas, t_flags *flags, wint_t arg)
{
	char		*argcvd;

	if (!(argcvd = ft_wctoa(arg)))
		return (NULL);
	if (flags->less == 1)
	{
		ft_aff_nulchar(datas);
		if (!(argcvd = ft_launch_lc_flags(&argcvd, datas, flags)))
			return (ft_exit_conv(datas, argcvd));
		if (!(datas->result = ft_strdup(argcvd)))
			return (ft_exit_conv(datas, argcvd));
		ft_strdel(&argcvd);
	}
	else
	{
		if (!(argcvd = ft_launch_lc_flags(&argcvd, datas, flags)))
			return (ft_exit_conv(datas, argcvd));
		if (!(datas->result = ft_strjoin(datas->result, argcvd)))
			return (ft_exit_conv(datas, argcvd));
		ft_aff_nulchar_clean(datas);
		if (!(datas->result = ft_strnew(0)))
			return (ft_exit_conv(datas, argcvd));
		ft_strdel(&argcvd);
	}
	return (datas->result);
}

static char		*ft_prepare_lc_conv(t_datas *datas, t_flags *flags, wint_t arg)
{
	if (arg == 0)
	{
		if (flags->padding != 0)
			flags->padding -= 1;
		if (!(datas->result = ft_lc_dont_exist(datas, flags, arg)))
			return (NULL);
	}
	else
	{
		if (!(datas->result = ft_lc_exist(datas, flags, arg)))
			return (NULL);
	}
	return (datas->result);
}

char			*ft_get_lc_conv(t_datas *datas)
{
	va_list		copy;
	wint_t		arg;
	t_flags		flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (NULL);
	if (datas->un_ord == 1)
	{
		va_copy(copy, datas->ap);
		while (flags.dollar-- > 0)
			va_arg(copy, void *);
		arg = va_arg(copy, wint_t);
		va_end(copy);	
	}
	else
		arg = va_arg(datas->ap, wint_t);
	if (!(datas->result = ft_prepare_lc_conv(datas, &flags, arg)))
		return (NULL);
	return (datas->result);
}




















