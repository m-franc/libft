/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:13:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 12:56:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_p_arg(t_datas *datas)
{
	void	*arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, void*)))
		return (NULL);
	if (!(argcvd = ft_vtop(arg)))
		return (NULL);
	if (!(new = ft_lststrnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
