/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/09 22:40:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_s_arg(t_datas *datas)
{
	char	*arg;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, char*)))
		return (NULL);
	if (!(new = ft_lstnew(arg, ft_strlen(arg))))
		return (NULL);
	return (new);
}

char	*ft_get_s_conv(t_datas *datas)
{
	char	*lastdatas;

	lastdatas = datas->result;
	if (!(datas->result = ft_strjoin(datas->result, datas->args->content)))
		return (NULL);
	datas->len += ft_strlen(datas->args->content);
	ft_strdel(&lastdatas);
	datas->args = datas->args->next;
	return (datas->result);
}
