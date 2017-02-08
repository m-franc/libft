/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:41:03 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/08 17:26:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s_conv(t_datas *datas)
{
	char	*arg;
	
	if (!(arg = va_arg(datas->args, char *)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, arg)))
		return (NULL);
	datas->len += ft_strlen(arg);
	return (datas->result);
}
