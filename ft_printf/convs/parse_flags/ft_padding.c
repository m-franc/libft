/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:00:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/06 19:31:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_n_arg_padding(t_datas *datas, int n, t_flags *flags, size_t *i)
{
	t_list	*valist;

	valist = datas->tmp_args;
	while (n -- > 0 && valist)
		valist = valist->next;
	flags->padding = ft_atoi(valist->content);
	*i += ft_ilen(n, 10) + 2;
	return (1);
}

int		ft_arg_padding(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i)
{
	int	result;
	int	len;

	if (datas->un_ord == 1)
	{
		if (strflag[0] >= '1' && strflag[0] <= '9')
		{
			result = ft_atoi(strflag);
			len = ft_ilen(result, 10);
			if (strflag[len] == '$')
				return (ft_n_arg_padding(datas, result - 1, flags, i));
			else
				return (-1);
		}
		else
			return (-1);
	}
	flags->padding = ft_atoi(datas->args->content);
	datas->args = datas->args->next;
	*i += 1;
	return (1);
}

int		ft_padding(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	int		result;
	int		len;

	if (strflag[0] < '1' && strflag[0] > '9')
		return (0);
	else if (strflag[0] == '*')
		return (ft_arg_padding(datas, strflag + 2, flags, i));
	else if (strflag[0] >= '1' && strflag[0] <= '9')
	{
		result = ft_atoi(strflag + 1);
		len = ft_ilen(result, 10);
		if (strflag[len + 1] == '$')
			return (-1);
		flags->padding = result;
		PSTR("PADDING : ")
		ft_putendl(flags->padding);
		*i += len;
		return (1);
	}
	return (0);
}
