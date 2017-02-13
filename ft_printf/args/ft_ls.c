/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/13 19:37:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_ls_arg(t_datas *datas)
{
	wchar_t	*arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, wchar_t*)))
		return (NULL);
	if (!(argcvd = ft_wstrtoa(arg)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_wstrlen(arg))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}

char	*ft_get_ls_conv(t_datas *datas)
{
	if (!(datas->result = ft_strjoin(datas->result, datas->args->content)))
		return (NULL);
	datas->len += datas->args->content_size;
	datas->args = datas->args->next;
	return (datas->result);
}
