/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:19:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/26 18:49:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putwchar(wchar_t uchar)
{
	size_t	i;
	size_t	size;
	int		msq;

	msq = 0b00000001;
	size = sizeof(uchar);
	i = 0;
	while (size > 0)
	{
		if (msq & uchar)
			write(1, &uchar, 1);
		uchar = uchar << ((8 * size) - 8);
		size--;
	}
}
