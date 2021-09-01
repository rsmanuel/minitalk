/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:14:00 by rmanuel           #+#    #+#             */
/*   Updated: 2021/06/22 16:05:10 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (0);
	i = 0;
	k = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[i] != '\0')
		s3[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[k++] = s2[i++];
	s3[k] = '\0';
	return (s3);
}
