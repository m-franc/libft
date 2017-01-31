/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/31 19:43:31 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char *s, char c)
{
	char	*new;
	int		newlen;
	int		i;

	i = 0;
	newlen = ft_strlen(s) + 1;
	if (!(new = ft_strnew(newlen)))
		return (NULL);
	if (!s)
	{
		*new = c;
		return (new);
	}
	while (*s)
		new[i++] = *s++;
	new[i++] = c;
	return (new);
}
