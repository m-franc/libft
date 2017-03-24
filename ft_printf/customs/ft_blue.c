/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:49:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_blue(char **s, char *buffpc, int *i)
{
	char	*blue;
	char	*new;
	char	*color;

	if (!(blue = ft_strdup("{blue}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, blue, ft_strlen(blue))))
		return (ft_exit_color(blue));
	if (!(color = ft_strjoin(buffpc, BLUE)))
		return (-1);
	*i += ft_strlen(blue);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&blue);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
