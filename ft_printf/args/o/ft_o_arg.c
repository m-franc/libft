/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:07:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:34:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_o_arg(t_datas *datas)
{
	unsigned int	arg;
	char			*argcvd;
	t_list			*new;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'z'))
		return (ft_get_lo_arg(datas));
	else
	{
		arg = va_arg(datas->ap, unsigned int);
		if (ft_strstr(datas->flags, "hh"))
			arg = (unsigned char)arg;
		else if (ft_strchr(datas->flags, 'h'))
			arg = (unsigned short)arg;
		if (!(argcvd = ft_uitoa(arg, 8, BASEUP)))
			return (NULL);
	}
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
