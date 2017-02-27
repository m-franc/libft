/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:14:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:53:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_get_d_arg(t_datas *datas)
{
	int	arg;
	char	*argcvd;
	t_list	*new;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
|| ft_strchr(datas->flags, 'z'))
		return (ft_get_ld_arg(datas));
	else
	{
		arg = va_arg(datas->ap, int);
		if (ft_strstr(datas->flags, "hh"))
			arg = (char)arg;
		else if (ft_strchr(datas->flags, 'h'))
			arg = (short)arg;
		if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
			return (NULL);
	}
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
