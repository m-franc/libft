/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:06:23 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/13 19:58:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	int				size;

	size = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(result = (char*)malloc(sizeof(char) * (size) + 1)))
		return (NULL);
	if (n < 0)
		*result = '-';
	result[size--] = '\0';
	if (n <= 9 && n >= 0)
		result[size--] = '0' + n;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		result[size--] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
