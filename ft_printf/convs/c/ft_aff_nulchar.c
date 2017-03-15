/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_nulchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:13:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 12:13:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aff_nulchar(t_datas *datas)
{
	datas->cplen = datas->len + datas->cplen + 1;
	write(1, datas->result, datas->len);
	write(1, "\0", 1);
	datas->len = 0;
}
