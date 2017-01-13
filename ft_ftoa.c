/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/13 20:45:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(float n)
{
	char	*first;
	char	*second;
	char	*getdot;
	char	*result;
	float	tmp;

	if (!(first = ft_itoa(n)))
		return (NULL);
	n = (n - atoi(first)) * 100;
	n = ABS(n);
	tmp = n;
	while (((int)tmp % 10) != 0)
	{
		n *= 10;
		tmp /= 10;
	}
	if (!(second = ft_itoa(n)))
		return (NULL);
	getdot = ft_strjoin(first, ".");
	ft_strdel(&first);
	first = getdot;
	result = ft_strjoin(first, second);
	ft_strdel(&getdot);
	ft_strdel(&second);
	return (result);
}
