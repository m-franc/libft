/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/10 20:03:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_n_conv(t_datas *datas)
{
	int		*cp_len;

	if (!(cp_len = va_arg(datas->ap, int*)))
		return (NULL);
	datas->tmp_len = cp_len;
	*datas->tmp_len = datas->len;
	return (datas->result);
}
