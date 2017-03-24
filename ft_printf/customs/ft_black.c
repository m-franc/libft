/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_black.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:48:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_black(char **s, char *buffpc, int *i)
{
	char	*black;
	char	*new;
	char	*color;

	if (!(black = ft_strdup("{black}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, black, ft_strlen(black))))
		return (ft_exit_color(black));
	if (!(color = ft_strjoin(buffpc, BLACK)))
		return (-1);
	*i += ft_strlen(black);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&black);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
