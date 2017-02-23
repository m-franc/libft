/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 19:20:03 by mfranc           ###   ########.fr       */
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
