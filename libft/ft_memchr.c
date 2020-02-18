/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:11:00 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		a;
	const unsigned char	*dst;
	int					i;

	dst = s;
	i = 0;
	a = c;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (dst[i] == a)
			return ((void *)&dst[i]);
		i++;
		n--;
	}
	return (NULL);
}
