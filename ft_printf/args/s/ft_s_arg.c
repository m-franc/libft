/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 13:01:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_s_arg(t_datas *datas)
{
	char	*arg;
	t_list	*new;
	
	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_ls_arg(datas));
	arg = va_arg(datas->ap, char*);
	if (!(new = ft_lststrnew(arg, ft_strlen(arg))))
		return (NULL);
	return (new);
}
