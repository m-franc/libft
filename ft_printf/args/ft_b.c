/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/15 15:52:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_get_b_arg(t_datas *datas)
{
	void	*arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, void*)))
		return (NULL);
	if (!(argcvd = ft_vtob(arg, 8)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
char	*ft_get_b_conv(t_datas *datas)
{
	if (!(datas->result = ft_strjoin(datas->result, datas->args->content)))
		return (NULL);
	datas->len += datas->args->content_size;
	datas->args = datas->args->next;
	return (datas->result);
}