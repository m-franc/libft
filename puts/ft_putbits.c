/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:50:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/25 19:11:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putbits(const void *c, size_t size)
{
	unsigned char	msq;
	char			result[9 * size];
	int				i;
	size_t			o;

	i = 0;
	o = 0;
	while (o < size)
	{
		msq = 0b0000001;
		while (msq)
		{
			if (*(char*)c & msq)
				result[i++] = '1';
			else
				result[i++] = '0';
			msq = (msq << 1);
		}
		if (i != (9 * size - 1))
			result[i++] = 32;
		c++;
		o++;
	}
	result[i] = '\0';
	ft_putstr(ft_strrev(result));
}