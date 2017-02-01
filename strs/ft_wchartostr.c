/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:16:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/01 19:53:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get4bytewchar(wint_t uchar)
{
	return (NULL);
}

static	char	*get3bytewchar(wint_t uchar)
{
	int				msq;
	int				msq2;
	int				tmp;
	char			*result;

	if (!(result = ft_strnew(3)))
		return (NULL);
	msq = 0b00111111;
	msq2 = 0b00011111;

	ft_putendl(ft_vtob(&uchar, sizeof(uchar)));
	tmp = msq & uchar;
	ft_putendl(ft_vtob(&tmp, sizeof(tmp)));
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
	while (msq2)
	{
		if (uchar)
		msq = msq << 1;
	}
	return (result);
}

char			*ft_wchartostr(wint_t uchar)
{
//	int a = 0;
//	int b = 127;
//	int c = 128;
//	int d = 2047;
//	int e = 2048;
//	int f = 65535;
//	int g = 65536;
//	int h = 1114111;
//	printf("Dimension 1 octet : %s - %s\n", ft_vtob(&a, sizeof(a)), ft_vtob(&b, sizeof(b)));
//	printf("Dimension 2 octet : %s - %s\n", ft_vtob(&c, sizeof(c)), ft_vtob(&d, sizeof(d)));
//	printf("Dimension 3 octet : %s - %s\n", ft_vtob(&e, sizeof(e)), ft_vtob(&f, sizeof(f)));
//	printf("Dimension 4 octet : %s - %s\n", ft_vtob(&g, sizeof(g)), ft_vtob(&h, sizeof(h)));
	
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
