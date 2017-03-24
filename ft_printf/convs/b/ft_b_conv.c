/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 21:49:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_b_conv(t_datas *datas)
{
	void	*arg;
	int		size;
	char	*argcvd;
	t_flags	flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		ft_exit(datas);
	if (ft_strstr(datas->flags, "hh"))
		size = 1;
	else if (ft_strchr(datas->flags, 'h'))
		size = 2;
	else if (ft_strchr(datas->flags, 'l'))
		size = 8;
	else
		size = 4;
	arg = va_arg(datas->ap, void*);
	if (!(argcvd = ft_vtob(arg, size)))
		return (ft_exit_conv(datas, argcvd));
	if ((ft_d_padding(&argcvd, &flags)) == -1)
		ft_exit_conv(datas, argcvd);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
