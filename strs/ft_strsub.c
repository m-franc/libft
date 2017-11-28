/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:21:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/28 17:45:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char				*new;
	unsigned int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(new = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
