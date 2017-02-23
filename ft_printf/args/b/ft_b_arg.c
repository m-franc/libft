/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:13:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:02:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*ft_get_b_arg(t_datas *datas)
{
	void	*arg;
	char	*argcvd;
	t_list	*new;

	if (!(arg = va_arg(datas->ap, void*)))
		return (NULL);
	if (!(argcvd = ft_vtob(arg, 8)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
