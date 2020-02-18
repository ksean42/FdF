/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:57:40 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char *s;
	unsigned char		a;
	size_t				i;

	a = (unsigned char)c;
	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == a)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
