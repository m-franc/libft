/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:00:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/10 20:00:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	int		len;
	char	*result;
	int		i;
	int		ln;

	if (base >= 17 && base < 1)
		return (NULL);
	ln = (long int)n;
	len = ft_intlen(ln);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ln < 0 && base == 10)
		result[0] = '-';
	result[len--] = '\0';
	i = 1;
	if (ln >= 0 && ln <= 9)
		result[len--] = BASE[ln];
	if (ln < 0 && base == 10)
		ln = -n;
	while (ln != 0)
	{
		result[len--] = BASE[ln % base];
		ln /= base;
	}
	return (result);
}
