/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:01:49 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = len;
	d = dst;
	s = src;
	if (d != s)
	{
		if (s > d)
			ft_memcpy(dst, src, len);
		else if (s < d)
		{
			while (i > 0)
			{
				d[i - 1] = s[i - 1];
				i--;
			}
		}
	}
	return (dst);
}
