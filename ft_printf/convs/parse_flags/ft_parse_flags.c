/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:44:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/15 18:58:39 by mfranc           ###   ########.fr       */
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

static void	ft_prepare_init(t_flags *flags)
{
	flags->dollar = 0;
	flags->precision = -1;
	flags->less = 0;
	flags->zero = 0;
	flags->diese = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->padding = 0;
}

int			ft_flags_init(t_datas *datas, t_flags *flags)
{
	size_t	*i;
	size_t	a;
	size_t	o;

	a = 0;
	i = &a;
	ft_prepare_init(flags);
	while (datas->flags[*i])
	{
		o = 0;
		while (o < 7)
		{
			if (ft_strspn(datas->flags + *i, "lhjz") > 0)
				*i += 1;
			if ((g_get_flags[o++](datas, datas->flags + *i, flags, i)) == -1)
				return (-1);
		}
	}
	return (0);
}
