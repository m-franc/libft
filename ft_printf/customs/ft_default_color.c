/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:34:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_default_color(char **s, char *buffpc, int *i)
{
	char	*d;
	char	*new;
	char	*color;

	if (!(d = ft_strdup("{eoc}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, d, ft_strlen(d))))
		return (ft_exit_color(d));
	if (!(color = ft_strjoin(buffpc, DEFAULT)))
		return (-1);
	*i += ft_strlen(d);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&d);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
