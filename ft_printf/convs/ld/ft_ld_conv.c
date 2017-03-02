/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:27:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_ld_conv(t_datas *datas)
{
	if (!(datas->result = ft_strjoin(datas->result, datas->args->content)))
		return (NULL);
	datas->len += datas->args->content_size;
	datas->args = datas->args->next;
	return (datas->result);
}
