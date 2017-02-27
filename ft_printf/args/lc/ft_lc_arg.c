/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:02:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:53:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_lc_arg(t_datas *datas)
{
	wint_t	arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, wint_t)))
		return (NULL);
	if (!(argcvd = ft_wctoa(arg)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
