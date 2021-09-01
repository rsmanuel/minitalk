/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:37:17 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/24 11:55:47 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dst && !src)
		return (0);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s >= d)
		return (ft_memcpy(d, s, len));
	else
	{
		while (i < len)
		{
			d[len - 1 - i] = s[len - 1 - i];
			i++;
		}
	}
	return (d);
}
