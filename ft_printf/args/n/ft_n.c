/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 21:05:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 12:24:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_n_arg(t_datas *datas)
{
	t_list	*new;
	int		*cp_len;
	char	*msg;

	if (!(msg = ft_strdup("Here we catch the tmp len datas")))
		return (NULL);
	if (!(cp_len = va_arg(datas->ap, int*)))
		return (NULL);
	datas->tmp_len = cp_len;
	PSTR("LEN : ")
	ft_putintendl(*datas->tmp_len, 10, BASEUP);
	if (!(new = ft_lstnew(msg, sizeof(msg))))
		return (NULL);
	ft_strdel(&msg);
	return (new);
}

char	*ft_get_n_conv(t_datas *datas)
{
	*datas->tmp_len = datas->len;
//	write(1, datas->result, datas->len);
//	ft_putintendl(datas->len, 10, BASEUP);
//	ENDL
	datas->args = datas->args->next;
	return (datas->result);
}
