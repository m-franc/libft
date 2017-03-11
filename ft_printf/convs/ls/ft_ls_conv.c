/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:03 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/11 13:01:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_ls_conv(t_datas *datas)
{
	wchar_t	*arg;
	char	*argcvd;

	arg = va_arg(datas->ap, wchar_t*);
	if (arg == NULL)
	{
		if (!(argcvd = ft_strdup("(null)")))
			return (NULL);
		datas->len += ft_strlen(argcvd);
	}
	else
	{
		if (!(argcvd = ft_wstrtoa(arg)))
			return (NULL);	
		datas->len += ft_wstrlen(arg);
	}
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (NULL);
	ft_strdel(&argcvd);
	return (datas->result);
}
