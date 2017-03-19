/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:55:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/16 12:17:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_get_percent_conv(t_datas *datas)
{
	char		*argcvd;
	t_flags		flags;

	if (!(argcvd = ft_straddchar(NULL, '%')))
		return (NULL);
	if ((ft_flags_init(datas, &flags)) == -1)
		return (NULL);
	if (!(argcvd = ft_launch_c_flags(&argcvd, &flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len = ft_strlen(datas->result);
	ft_strdel(&argcvd);
	return (datas->result);
}

