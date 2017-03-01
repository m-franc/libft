/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/01 19:01:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_star(t_datas *datas)
{
	int		arg;

	arg = va_arg(datas->ap, int);
	return (arg);
}

void	ft_get_num_flag(t_datas *datas, size_t conv_index, char *buff, t_list *tmp)
{
	size_t	i;

	i = -1;
	while (datas->flags[++i])
	{
		if (datas->flags[i] == '.')
		{
			if (datas->flags[i + 1] == '*')
				tmp->precision = ft_get_star(datas);
			else if (datas->flags[i + 1] <= '9' && datas->flags[i + 1] >= '0')
				tmp->precision = ft_atoi(datas->flags + (i + 1));
		}
		else if (datas->flags[i] == '*')
			tmp->padding = ft_get_star(datas);
		else if (datas->flags[i] <= '9' && datas->flags[i] >= '0')
		{
			if (datas->flags[i + 1] == '$' && tmp->index == 0)
				tmp->index = ft_atoi(datas->flags + i);
			tmp->padding = ft_atoi(datas->flags + i);
		}
	}
}
