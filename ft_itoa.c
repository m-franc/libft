/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:00:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/15 17:59:50 by mfranc           ###   ########.fr       */
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
	return (result);
}
