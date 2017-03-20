/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_datasmanager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:32:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/20 20:09:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_last_datasmanager(t_datas *datas, char conv, char **lastdatas)
{
	if (datas->len == 0 && datas->cplen == 0 && (conv == 'n' || conv == 'w'))
		datas->result = NULL;
	if (datas->result && (conv != 'n' || conv != 'w'))
		ft_strdel(lastdatas);
}
