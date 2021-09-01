/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:51:25 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/08 18:33:59 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	newc;

	newc = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == newc)
			return (str);
		str++;
	}
	if (newc == *str)
		return (str);
	return (NULL);
}
