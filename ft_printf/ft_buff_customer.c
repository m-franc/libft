/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_customer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:10:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 12:58:55 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_custom(char *s, int *i)
{
	char	**tab;
	char	**tabcstm;
	int		j;

	if (!(tab = ft_strsplit(CSTMLIST, ',')))
		return (-1);
	if (!(tabcstm = ft_strsplit(CODECSTM, ',')))
		return (-1);
	j = -1;
	while (tab[--j])
	{
		if (ft_strstr(s, tab[j]))
		{
			if (!(s = ft_strjoin(s, tabcstm[j])))
				return (-1);
			*i += ft_strlen(tab[j]);
			return (1);
		}
	}
	return (0);
}

int			ft_buff_customer(char **ucvchar)
{
	int		i;

	if (!(ft_strchr(*ucvchar, '{')))
		return (0);
	else
	{
		i = -1;
		while (*ucvchar[++i])
		{
			if (*ucvchar[i] == '{')
			{
				if ((ft_find_custom(*ucvchar + i, &i)) == -1)
					return (-1);
			}
		}
		return (1);
	}
}
