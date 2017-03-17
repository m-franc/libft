/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_customer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:10:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:56:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_customs	g_customs[] = 
{
	ft_blue, ft_red, ft_black, ft_purple, ft_cyan,
	ft_yellow, ft_green, ft_grey, ft_eoc,
};

int			ft_exit_color(char *color)
{
	ft_strdel(&color);
	return (0);
}

static int	ft_find_custom(char **s, int *i)
{
	int		j;
	char	*buffpc;
	int		process;

	j = 0;
	if (!(buffpc = ft_strsub(*s, 0, *i)))
		return (-1);
	while (j < 9)
	{
		process = g_customs[j](s, buffpc, i);
		if (process == -1)
			return (-1);
		else if (process == 1)
			return (1);
		j++;
	}
	ft_strdel(&buffpc);
	return (0);
}

int			ft_buff_customer(char **ucvchar)
{
	int		i;
	char	*tmp;

	if (!(ft_strchr(ucvchar[0], '{')))
		return (0);
	else
	{
		i = -1;
		while (ucvchar[0][++i])
		{
			if (ucvchar[0][i] == '{')
			{
				if ((ft_find_custom(ucvchar, &i)) == -1)
					return (-1);
			}
		}
		return (1);
	}
}
