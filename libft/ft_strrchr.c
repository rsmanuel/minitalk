/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:51:34 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/24 12:46:41 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	newc;

	str = (char *)s;
	len = ft_strlen(str);
	newc = (char)c;
	while (len != 0 && str[len] != newc)
		len--;
	if (str[len] == newc)
		return (&str[len]);
	return (NULL);
}
