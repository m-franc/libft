/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:44:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/08 19:37:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_flags	g_get_flags[] =
{
	ft_precision,
	ft_padding,
	ft_less,
	ft_zero,
	ft_diese,
	ft_plus,
	ft_space
};

int		ft_flags_init(t_datas *datas)
{
	size_t	i;
	size_t	o;
	t_flags	flags;

	i = -1;
	flags.dollar = 0;
	flags.precision = 0;
	flags.less = 0;
	flags.zero = 0;
	flags.diese = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.padding = 0;
	while (datas->flags[++i])
	{
		o = 0;
		while (o < 7)
		{
			if ((g_get_flags[o++](datas, datas->flags + i, &flags, &i)) == -1)
				return (-1);
		}
	}
	return (0);
}
