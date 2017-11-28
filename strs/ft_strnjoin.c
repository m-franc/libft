/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:01:20 by mfranc            #+#    #+#             */
/*   Updated: 2017/10/31 16:51:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t size)
{
	char	*combin;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len = (size >= ft_strlen(s2)) ? ft_strlen(s1) + ft_strlen(s2)
									: ft_strlen(s1) + size;
	if (!(combin = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	i = -1;
	while (s1[++i])
		combin[i] = s1[i];
	j = 0;
	while (s2[j] && j < size)
		combin[i++] = s2[j++];
	combin[i] = '\0';
	return (combin);
}
