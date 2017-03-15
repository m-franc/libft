/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:55:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 19:47:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_c_flags[] = 
{
	ft_c_zero, ft_d_padding, ft_c_precision,
};

char			*ft_launch_c_flags(char **argcvd,
		t_datas *datas, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 3)
	{
		if ((g_c_flags[nb_flags++](argcvd, datas, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

static char		*ft_c_exist(t_datas *datas, t_flags *flags, int arg)
{
	char		*argcvd;

	if (!(argcvd = ft_straddchar(NULL, arg)))
		return (NULL);
	if (!(argcvd = ft_launch_c_flags(&argcvd, datas, flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len = ft_strlen(datas->result);
	ft_strdel(&argcvd);
	return (datas->result);
}

static char		*ft_c_dont_exist(t_datas *datas, t_flags *flags, int arg)
{
	char		*argcvd;

	if (!(argcvd = ft_straddchar(NULL, arg)))
		return (NULL);
	if (flags->less == 1)
	{
		ft_aff_nulchar(datas);
		if (!(argcvd = ft_launch_c_flags(&argcvd, datas, flags)))
			return (ft_exit_conv(datas, argcvd));
		if (!(datas->result = ft_strdup(argcvd)))
			return (ft_exit_conv(datas, argcvd));
		ft_strdel(&argcvd);
	}
	else
	{
		if (!(argcvd = ft_launch_c_flags(&argcvd, datas, flags)))
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

static char		*ft_prepare_c_conv(t_datas *datas)
{
	t_flags		flags;
	int			arg;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (NULL);
	if (datas->un_ord == 1)
		arg = ft_n_d(datas, &flags);
	else
		arg = va_arg(datas->ap, int);
	if (arg == 0)
	{
		if (flags.padding != 0)
			flags.padding -= 1;
		if (!(datas->result = ft_c_dont_exist(datas, &flags, arg)))
			return (NULL);
	}
	else
	{
		if (!(datas->result = ft_c_exist(datas, &flags, arg)))
			return (NULL);
	}
	return (datas->result);
}

char			*ft_get_c_conv(t_datas *datas)
{
	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_lc_conv(datas));
	if (!(datas->result = ft_prepare_c_conv(datas)))
		return (NULL);
	return (datas->result);
}

