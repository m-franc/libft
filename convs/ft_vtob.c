/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:14:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/01 15:07:29 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_vtob(const void *c, size_t size)
{
	unsigned char	msq;
	char			*result;
	int				i;
	size_t			o;

	i = 0;
	o = 0;
	if (!(result = ft_strnew(8 * size)))
		return (NULL);
	while (o < size)
	{
		msq = 0b0000001;
		while (msq)
		{
			result[i++] = (*(char*)c & msq) ? '1' : '0';
			msq = (msq << 1);
		}
		c++;
		o++;
	}
	return (ft_strrev(result));
}
