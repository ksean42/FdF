/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:37:11 by ksean             #+#    #+#             */
/*   Updated: 2020/01/17 16:32:04 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_countw(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	if (str[i] != c && str[i])
		word++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

static int				ft_outwords(char *s, char **dest, char c, int j)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(dest[j] = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (*s != c && *s != '\0')
	{
		dest[j][i] = *s;
		s++;
		i++;
	}
	dest[j][i] = '\0';
	return (1);
}

static void				ft_free(char **dest, int j)
{
	while (j--)
		free(dest[j]);
	free(dest);
}

static int				ft_check(const char *s, char **dest, char c, int j)
{
	if (ft_outwords((char *)s, dest, c, j) == 0)
	{
		ft_free(dest, j);
		return (1);
	}
	return (0);
}

char					**ft_strsplit(const char *s, char c)
{
	char	**dest;
	int		j;
	int		w;

	if (s == NULL)
		return (NULL);
	w = ft_countw((char*)s, c);
	j = 0;
	if (!(dest = (char**)malloc(sizeof(char*) * (w + 1))))
		return (NULL);
	while (*s != '\0' && j < w)
	{
		if (*s != c)
		{
			if (ft_check(s, dest, c, j) == 1)
				return (NULL);
			j++;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s != '\0')
			s++;
	}
	dest[j] = NULL;
	return (dest);
}
