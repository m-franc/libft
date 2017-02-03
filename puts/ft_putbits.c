/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:01:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/03 16:58:24 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits(const void *s, size_t size)
{
	char	*binary;

	if (!s)
		return ;
	if (!(binary = ft_vtob(s, 4)))
		return ;
	ft_putstr(binary);
	ft_strdel(&binary);
}
