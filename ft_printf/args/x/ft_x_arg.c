/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:15:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:36:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_x_arg(t_datas *datas)
{
	unsigned long long	arg;
	char				*argcvd;
	t_list				*new;

	if (!(arg = va_arg(datas->ap, unsigned long long)))
		return (NULL);
	if (!(argcvd = ft_uitoa(arg, 16, BASELW)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
