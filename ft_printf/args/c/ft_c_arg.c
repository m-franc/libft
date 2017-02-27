/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:51:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:52:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_c_arg(t_datas *datas)
{
	int			arg;
	char			*argcvd;
	t_list			*new;

	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_lc_arg(datas));
	arg = va_arg(datas->ap, int);
	if (!(argcvd = ft_straddchar(NULL, arg)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
