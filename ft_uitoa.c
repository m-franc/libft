/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:00:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/15 18:35:56 by mfranc           ###   ########.fr       */
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
