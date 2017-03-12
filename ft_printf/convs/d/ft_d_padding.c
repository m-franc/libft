/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/12 19:42:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_padding(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->padding == 0)
		return (0);
	nb_o = -1;
	if (!(tmp = ft_strnew(flags->padding)))
		return (-1);
	if (flags->less == 1)
	{
		tmp = ft_strncpy(tmp, *argcvd, ft_strlen(*argcvd));	
		nb_o = ft_strlen(*argcvd);
		while (nb_o < flags->padding)
			tmp[nb_o++] = ' ';
		ft_strdel(argcvd);
		*argcvd = tmp;
		return (1);
	}
	while (++nb_o < ((flags->padding) - ((ft_strlen(*argcvd)))))
		tmp[nb_o] = ' ';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
