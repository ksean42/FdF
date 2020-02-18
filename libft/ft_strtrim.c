/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:17:10 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	min;
	size_t	max;

	i = 0;
	min = 0;
	if (s == NULL)
		return (NULL);
	max = ft_strlen(s);
	while (s[min] == ' ' || s[min] == ',' || s[min] == '\n' || s[min] == '\t')
		min++;
	if (min == max)
		return (ft_strnew(1));
	while (s[max] == '\0' || s[max] == ' ' || s[max] == ',' || s[max] == '\n'
	|| s[max] == '\t')
		max--;
	return (ft_strsub(s, min, max - min + 1));
}
