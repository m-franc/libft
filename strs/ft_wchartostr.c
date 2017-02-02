/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:16:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/02 20:45:44 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get4bytewchar(wint_t uchar)
{
	return (NULL);
}

static	char	*get3bytewchar(wint_t uchar)
{
	int				tmp;
	int				tmp2;
	char			*result;
	int 			msq;
	int				msq2;

	if (!(result = ft_strnew(3)))
		return (NULL);
//	msq = 0b11000000;
	PSTR("LORIGINAL                                : ")
	ft_putendl(ft_vtob(&uchar, sizeof(uchar)));
	PSTR("DEUXIEME OCTET                           : ")
	tmp2 = uchar & 0xFC0;
	tmp2 = tmp2 << 2;
	ft_putendl(ft_vtob(&tmp2, sizeof(tmp2)));
	PSTR("TROISIEME OCTET                          : ")
	tmp = uchar & 0xF000;
	tmp = tmp << 4;
	ft_putendl(ft_vtob(&tmp, sizeof(tmp)));
	tmp2 = (uchar & 0x3F) | tmp2 | tmp;
	PSTR("FUSION DES DEUX AVEC LE PREMIER          : ")
	ft_putendl(ft_vtob(&tmp2, sizeof(tmp2)));
	msq2 = 0xE08080;
	tmp2 = tmp2 | msq2;
	PSTR("FUSION DES DEUX AVEC LE PREMIER ET LES 1 : ")
	ft_putendl(ft_vtob(&tmp2, sizeof(tmp2)));
	ENDL
	ENDL
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
/*	int a = 0;
	int b = 127;
	int c = 128;
	int d = 2047;
	int e = 2048;
	int f = 65535;
	int g = 65536;
	int h = 1114111;
	printf("Dimension 1 octet : %s - %s\n", ft_vtob(&a, sizeof(a)), ft_vtob(&b, sizeof(b)));
	printf("Dimension 2 octet : %s - %s\n", ft_vtob(&c, sizeof(c)), ft_vtob(&d, sizeof(d)));
	printf("Dimension 3 octet : %s - %s\n", ft_vtob(&e, sizeof(e)), ft_vtob(&f, sizeof(f)));
	printf("Dimension 4 octet : %s - %s\n", ft_vtob(&g, sizeof(g)), ft_vtob(&h, sizeof(h)));
	*/
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
