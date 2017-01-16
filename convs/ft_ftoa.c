/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/15 17:44:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_precision(float n)
{
	char	*precision;

	if (!(precision = ft_itoa(n, 10, BASELW)))
		return (NULL);
	return (precision);
}

char		*ft_ftoa(long double n)
{
	char		*first;
	char		*second;
	char		*getdot;
	char		*result;
	long double	tmp;

	if (!(first = ft_itoa(n, 10, BASELW)))
		return (NULL);
	n = ((n - ft_atoi(first)) * 100);
	n = ABS(n);
	tmp = n;
	while (((int)tmp % 10) != 0)
	{
		n *= 10;
		tmp /= 10;
	}
	n = n * 10;
	second = ft_get_precision(n);
	getdot = ft_strjoin(first, ".");
	ft_strdel(&first);
	first = getdot;
	result = ft_strjoin(first, second);
	ft_strdel(&getdot);
	ft_strdel(&second);
	return (result);
}
