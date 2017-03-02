/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:28:29 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_n_conv(t_datas *datas)
{
	*datas->tmp_len = datas->len;
	datas->args = datas->args->next;
	return (datas->result);
}
