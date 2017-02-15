/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:05:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/15 20:55:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_n_arg(t_datas *datas)
{
	t_list	*new;
	int		*len;
	char	*msg;

	if (!(msg = ft_strdup("Here we get the len when it ask")))
		return (NULL);
	if (!(len = va_arg(datas->ap, int*)))
		return (NULL);
	datas->cp_len = len;
	ft_putintendl(*datas->cp_len, 10, BASEUP);
	if (!(new = ft_lstnew(msg, sizeof(msg))))
		return (NULL);
	ft_strdel(&msg);
	return (new);
}

char	*ft_get_n_conv(t_datas *datas)
{
	int	*new;

	new = datas->cp_len;
	*new = datas->len;
	datas->args = datas->args->next;
	return (datas->result);
}
