/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:39:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/18 19:44:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint_fd(unsigned long long n, int fd, int base, char *baselist)
{
	char	*number;

	if (fd < 0 || !baselist)
		return ;
	number = ft_uitoa(n, base, baselist);
	ft_putstr_fd(number, fd);
	ft_strdel(&number);
}
