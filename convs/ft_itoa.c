/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:58:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/16 11:58:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n, int base, char *baselist)
{
	int		len;
	char	*result;

	if (base >= 17 && base < 2)
		return (NULL);
	len = ft_ilen(n, base);
	if (!(result = ft_strnew(len)))
		return (NULL);
	if (n < 0 && base == 10)
		result[0] = '-';
	result[len--] = '\0';
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		result[len--] = baselist[n % base];
		n /= base;
	}
	if (n == 0)
		result[len--] = baselist[n % base];
	return (result);
}
