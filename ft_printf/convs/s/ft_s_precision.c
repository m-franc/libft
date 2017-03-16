/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:36:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/16 12:46:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_s_precision(char **argcvd, t_datas *datas, t_flags *flags)
{
	char	*tmp;

	if (flags->precision == -1 || flags->precision >= ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strsub(*argcvd, 0, flags->precision)))
		return (-1);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
