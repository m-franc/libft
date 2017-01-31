/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:19:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/31 21:29:32 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get4bytewchar(wint_t uchar)
{
	return (NULL);
}

static	char	*get3bytewchar(wint_t uchar)
{
	return (NULL);
}

static	char	*get2bytewchar(wint_t uchar)
{
	int			msq;
	int			msq2;
	int			i;
	char		*result;

	i = 0;
	if (!(result = ft_strnew(3)))
		return (NULL);
	msq = 0b11000000;
	msq2 = 0b10000000;
	uchar = uchar >> 3;
	if (uchar | msq)
		*result++ = uchar;
	uchar = uchar >> 7;
	if (uchar | msq2)
		*result++ = uchar;
	return (result);
}

char			*ft_wchartostr(wint_t uchar)
{
	if (uchar >= 0 && uchar <= 127)
		return (ft_straddchar(NULL, (char)uchar));
	else if (uchar >= 128 && uchar <= 2047)
		return (get2bytewchar(uchar));
	else if (uchar >= 2048 && uchar <= 65535)
		return (get3bytewchar(uchar));
	else if (uchar >= 65536 && uchar <= 1114111)
		return (get4bytewchar(uchar));
	return (NULL);
}
