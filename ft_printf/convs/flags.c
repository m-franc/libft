/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:44:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/28 14:55:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_init(t_datas *datas)
{
	t_flags	flags;
	flags.un = ft_memcpy("", "&1", 2);
	flags.deux = ft_memcpy("", " ", 1);
	flags.trois = ft_memcpy("", "78h", 3);
	PSTR((char*)&flags)
}
