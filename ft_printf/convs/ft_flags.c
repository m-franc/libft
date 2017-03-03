/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:44:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/03 21:04:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_flags	g_get_flags[] =
{
	ft_precision, /*ft_get_precision, ft_get_less, ft_get_zero, ft_get_diese,
				  ft_get_plus, ft_get_space*/
};

int		ft_n_arg_precision(t_datas *datas, int n, t_flags *flags, size_t *i)
{
	t_list	*valist;

	valist = datas->tmp_args;
	while (n-- > 0 && valist)
		valist = valist->next;
	flags->precision = ft_atoi(valist->content);
	*i += ft_ilen(n, 10) + 2;
	return (1);
}

int		ft_arg_precision(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i)
{
	int	result;
	int	len;
	if (strflag[0] >= '1' && strflag[0] <= '9')
	{
		result = ft_atoi(strflag);
		len = ft_ilen(result, 10);
		if (strflag[len] == '$')
			return (ft_n_arg_precision(datas, result, flags, i));
	}
	flags->precision = ft_atoi(datas->args->content);
	datas->args = datas->args->next;
	*i += 1;
	return (1);
}

int		ft_precision(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	int		result;
	int		len;

	if (strflag[0] != '.')
		return (0);
	if (strflag[1] == '*')
		return (ft_arg_precision(datas, strflag + 2, flags, i));
	else if (strflag[1] >= '1' && strflag[1] <= '9')
	{
		result = ft_atoi(strflag + 1);
		len = ft_ilen(result, 10);
		if (strflag[len + 1] == '$')
			return (-1);
		flags->precision = result;
		*i += len;
		return (1);
	}
	return (0);
}

//int		ft_get_num(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
//{
//	int		result;
//	int		len;
//
/*	len = 0;
	if (strflag[0] == '.')
		return (ft_precision(datas, strflag + 1, flags, i))
	else if (strflag[0] == '*' || (strflag[0] >= '1' && strflag[0] <= '9'))

		if (strflag[0] >= '1' && strflag[0] <= '9')
		{	
			len = ft_ilen(result, 10);
			result = ft_atoi(strflag);
		}
		else if (strflag[0] == '*')
		{	
			result = *(int*)datas->args->content;	
			datas->args = datas->args->next;
		}
		else
			return (0);
	if (*(strflag + len) == '$')
	{
		if (flags->dollar != 0)
			flags->dollar = result;
		PSTR("DOLLAR : ")
			ft_putintendl(flags->dollar, 10, BASEUP);
	}
	else
	{
		flags->padding = result;
		PSTR("PADDING : ")
			ft_putintendl(flags->padding, 10, BASEUP);
	}
	*i += len;
	return (0);
}
*/
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
		while (o < 1)
		{
			if ((g_get_flags[o++](datas, datas->flags + i, &flags, &i)) == -1)
				return (-1);
		}
	}
	return (0);
}
