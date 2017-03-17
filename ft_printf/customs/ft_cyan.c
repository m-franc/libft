/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:55:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_cyan(char **s, char *buffpc, int *i)
{
	char	*cyan;
	char	*new;
	char	*color;

	if (!(cyan = ft_strdup("{cyan}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, cyan, ft_strlen(cyan))))
		return (ft_exit_color(cyan));
	if (!(color = ft_strjoin(buffpc, CYAN)))
		return (-1);
	*i += ft_strlen(cyan);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&cyan);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
