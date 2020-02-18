/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:20:47 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t lend;
	size_t lens;

	j = 0;
	i = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (lend >= size)
		j = lens + size;
	else
		j = lens + lend;
	while (src[i] && (lend + 1) < size)
	{
		dst[lend] = src[i];
		i++;
		lend++;
	}
	dst[lend] = '\0';
	return (j);
}
