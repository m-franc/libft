/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:15:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/14 19:16:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_u_arg(t_datas *datas)
{
	unsigned int	arg;
	char			*argcvd;
	t_list			*new;

	if (!(arg = va_arg(datas->ap, unsigned int)))
		return (NULL);
	if (!(argcvd = ft_uitoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
