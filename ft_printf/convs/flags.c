/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:44:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/28 22:32:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_flags	g_get_flags[] =
{
	ft_get_num, /*ft_get_precision, ft_get_less, ft_get_zero, ft_get_diese,
	ft_get_plus, ft_get_space*/
};

int		ft_get_num(char *flags, t_datas *datas, size_t *i)
{
	int	result;
	int	len;

	if (ft_strlen(flags) < 2)
		return (-1);
	if (flags[0] >= '1' && flags[0] <= '9')
		result = ft_atoi(flags + 1);
	else if (flags[0] == '*')
	{	
		result = *(int*)datas->stars->content;
		datas->stars = datas->stars->next;
	}
	len = ft_ilen(result, 10);
	if (*(flags + len) == '$')
	{
		if (datas->dollar != 0)
			datas->dollar = result;
	}
	else
		datas->dollar = result;
	return (0);
}

int		ft_flags_init(t_datas *datas)
{
	size_t	i;
	size_t	o;

	i = -1;
	datas->dollar = 0;
	datas->precision = 0;
	datas->less = 0;
	datas->zero = 0;
	datas->diese = 0;
	datas->plus = 0;
	datas->space = 0;
	datas->padding = 0;
	while (datas->flags[++i])
	{
		o = 0;
		while (o < 1)
		{
			if ((g_get_flags[o++](datas->flags + i, datas, &i)) == -1)
				return (-1);
		}
	}
	return (0);
}
