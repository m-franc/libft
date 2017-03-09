/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/09 11:57:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_get_b_arg(t_datas *datas)
{
	void	*arg;
	int		size;
	char	*argcvd;
	t_list	*new;

	if (ft_strstr(datas->flags, "hh"))
		size = 1;
	else if (ft_strchr(datas->flags, 'h'))
		size = 2;
	else if (ft_strchr(datas->flags, 'l'))
		size = 8;
	else
		size = 4;
	arg = va_arg(datas->ap, void*);
	if (!(argcvd = ft_vtob(arg, size)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
