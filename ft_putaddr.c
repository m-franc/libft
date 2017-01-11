/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:30:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/11 20:47:48 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(const void *value)
{
	char				res[9];
	int					i;
	unsigned long		p;

	i = 8;
	p = (unsigned long)value;
	while ((p / 16) != 0)
	{
		res[i--] = BASELW[(p % 16)];
		p /= 16;
	}
	ft_putstr(ft_strcat("0x", res));
}
