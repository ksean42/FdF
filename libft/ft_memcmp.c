/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:38:53 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *sc1;
	const unsigned char *sc2;

	sc1 = s1;
	sc2 = s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*sc1 != *sc2)
			return (*sc1 - *sc2);
		sc1++;
		sc2++;
	}
	return (0);
}
