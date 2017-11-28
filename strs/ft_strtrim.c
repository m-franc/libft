/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:08:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/28 17:48:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	o;

	if (!s)
		return (NULL);
	o = 0;
	while (s[o] && (ft_is_separator(s[o]) || s[o] == '\n'))
		o++;
	i = o;
	while (s[i] && s[o])
		i++;
	i--;
	while (s[i] && s[o] && (ft_is_separator(s[i]) || s[i] == '\n'))
		i--;
	i++;
	return (ft_strsub((char*)s, o, i - o));
}
