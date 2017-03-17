/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:56:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_grey(char **s, char *buffpc, int *i)
{
	char	*grey;
	char	*new;
	char	*color;

	if (!(grey = ft_strdup("{grey}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, grey, ft_strlen(grey))))
		return (ft_exit_color(grey));
	if (!(color = ft_strjoin(buffpc, GREY)))
		return (-1);
	*i += ft_strlen(grey);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&grey);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
