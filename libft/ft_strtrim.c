/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:34:28 by rmanuel           #+#    #+#             */
/*   Updated: 2021/02/24 17:11:47 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] != '\0' && check_char_in_set(s1[start], set) == 1)
		start++;
	while (end > start && check_char_in_set(s1[end - 1], set) == 1)
		end--;
	trim = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (trim == NULL)
		return (0);
	while (start < end)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
