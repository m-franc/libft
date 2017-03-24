/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 21:12:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_exit_n(t_datas *datas)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	datas->len = 0;
	return (NULL);
}

char		*ft_get_n_conv(t_datas *datas)
{
	int		*cp_len;

	if (!(cp_len = va_arg(datas->ap, int*)))
		return (ft_exit_n(datas));
	datas->tmp_len = cp_len;
	*datas->tmp_len = datas->len;
	return (datas->result);
}
