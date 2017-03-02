/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 20:54:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_ls_arg(t_datas *datas)
{
	wchar_t	*arg;
	char	*argcvd;
	t_list	*new;

	arg = va_arg(datas->ap, wchar_t*);
	if (arg == NULL)
	{
		if (!(argcvd = ft_strdup("(null)")))
			return (NULL);
		if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
			return (NULL);
		ft_strdel(&argcvd);
		return (new);
	}
	if (!(argcvd = ft_wstrtoa(arg)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_wstrlen(arg))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
