/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <rmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:28:53 by rmanuel           #+#    #+#             */
/*   Updated: 2021/06/22 16:04:52 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_strs(char const *s, char c)
{
	int	i;
	int	nbstrs;
	int	found;

	i = 0;
	nbstrs = 0;
	found = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			found = 1;
		else if (found == 1)
		{
			found = 0;
			nbstrs++;
		}
		i++;
	}
	return (nbstrs);
}

static int	count_char_str(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**str_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static char	**ftsplit(char const *s, char **split, char c, int nbstrs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nbstrs)
	{
		k = 0;
		while (s[i] == c)
			i++;
		split[j] = (char *)malloc(sizeof(char) * (count_char_str(s, c, i) + 1));
		if (split[j] == NULL)
			return (str_free(split));
		while (s[i] != '\0' && s[i] != c)
		{
			split[j][k] = s[i];
			k++;
			i++;
		}
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nbstrs;

	if (!s)
		return (0);
	nbstrs = count_strs(s, c);
	split = (char **)malloc(sizeof(char *) * (nbstrs + 1));
	if (split == NULL)
		return (0);
	return (ftsplit(s, split, c, nbstrs));
}
