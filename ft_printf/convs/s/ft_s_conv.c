/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:06:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 18:03:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s_conv(t_datas *datas)
{
	char	*arg;

	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_ls_arg(datas));
	arg = va_arg(datas->ap, char*);
	if (arg == NULL)
	{
		if (!(arg = ft_strdup("(null)")))
			return (NULL);
		if (!(datas->result = ft_strjoin(datas->result, arg)))
			return (NULL);
		datas->len += ft_strlen(arg);
		ft_strdel(&arg);
		return (datas->result);
	}
	else
	{
		if (!(datas->result = ft_strjoin(datas->result, arg)))
			return (NULL);
		datas->len += ft_strlen(arg);
		return (datas->result);
	}
}
