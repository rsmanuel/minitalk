/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:51:26 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/24 12:36:29 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	j;

	dstlen = ft_strlen(dst);
	j = 0;
	if (dstsize <= dstlen)
		return (dstsize + ft_strlen(src));
	while (src[j] != '\0' && dstlen + j < (dstsize - 1))
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
	return (ft_strlen(src) + dstlen);
}
