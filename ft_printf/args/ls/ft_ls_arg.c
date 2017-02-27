/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:54:15 by mfranc           ###   ########.fr       */
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
	if (!(new = ft_lststrnew(argcvd, ft_wstrlen(arg))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
