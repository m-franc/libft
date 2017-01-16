/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:58:41 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/16 11:58:42 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned long long n, int base, char *baselist)
{
	int		len;
	char	*result;

	if (base >= 17 && base < 2)
		return (NULL);
	len = ft_uilen(n, base);
	if (!(result = ft_strnew(len)))
		return (NULL);
	result[len--] = '\0';
	while (n != 0)
	{
		result[len--] = baselist[n % base];
		n /= base;
	}
	return (result);
}
