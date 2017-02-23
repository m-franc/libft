/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:07:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/14 19:08:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_o_arg(t_datas *datas)
{
	int		arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, int)))
		return (NULL);
	if (!(argcvd = ft_itoa(arg, 8, BASEUP)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
