/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_nulchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:13:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/16 21:56:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_nulchar_clean(t_datas *datas)
{
	datas->len = ft_strlen(datas->result);
	datas->cplen = datas->len + datas->cplen + 1;
	write(datas->fd, datas->result, datas->len);
	write(datas->fd, "\0", 1);
	ft_strdel(&(datas->result));
	datas->len = 0;
}

void	ft_aff_nulchar(t_datas *datas)
{
	datas->len = ft_strlen(datas->result);
	datas->cplen = datas->len + datas->cplen + 1;
	write(datas->fd, datas->result, datas->len);
	write(1, "\0", 1);
	datas->len = 0;
}
