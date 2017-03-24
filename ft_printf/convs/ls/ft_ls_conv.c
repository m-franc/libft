/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:06:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 19:39:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_ls_flags[] =
{
	ft_ls_precision, ft_c_zero, ft_d_padding
};

static char	*ft_launch_ls_flags(char **argcvd, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 3)
	{
		if ((g_ls_flags[nb_flags++](argcvd, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

static char	*ft_get_argcvd(wchar_t **argcvd)
{
	char	*newarg;

	if (*argcvd == NULL)
	{
		if (!(newarg = ft_strdup("(null)")))
			return (NULL);
		return (newarg);
	}
	else
	{
		if (!(newarg = ft_wstrtoa(*argcvd)))
			return (NULL);
		return (newarg);
	}
}

char		*ft_get_ls_conv(t_datas *datas)
{
	char	*argcvd;
	wchar_t	*arg;
	t_flags	flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (NULL);
	if (datas->un_ord == 1)
		arg = (wchar_t *)ft_n_s(datas, &flags);
	else
		arg = va_arg(datas->ap, wchar_t *);
	if (!(argcvd = ft_get_argcvd(&arg)))
		return (ft_exit_conv(datas, argcvd));
	if (!(argcvd = ft_launch_ls_flags(&argcvd, &flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
