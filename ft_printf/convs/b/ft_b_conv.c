/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 21:27:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_b_conv(t_datas *datas)
{
	if (!(datas->result = ft_strjoin(datas->result, datas->args->content)))
		return (NULL);
	datas->len += datas->args->content_size;
	datas->args = datas->args->next;
	return (datas->result);
}
