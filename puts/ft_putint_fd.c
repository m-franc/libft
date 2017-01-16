/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:50:12 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/15 18:38:42 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint_fd(long long int n, int fd, int base, char *baselist)
{
	ft_putstr_fd(ft_itoa(n, base, baselist), fd);
}
