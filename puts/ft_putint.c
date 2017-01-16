/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:41:57 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/15 18:38:31 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint(long long int n, int base, char *baselist)
{
	char	*number;

	number = ft_itoa(n, base, baselist);
	ft_putstr(number);
	ft_strdel(&number);
}
