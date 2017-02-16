/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/15 20:28:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_star_arg(t_datas *datas)
{
	t_list	*star;
	int		arg;

	if (!(arg = va_arg(datas->ap, int)))
		return (NULL);
	if (!(star = ft_lstnew(&arg, sizeof(arg))))
		return (NULL);
	ft_putintendl(arg, 10, BASEUP);
	return (star);
}
