/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:18:06 by ksean             #+#    #+#             */
/*   Updated: 2019/10/20 11:23:16 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char			a;
	int						i;
	unsigned char			*str;

	i = 0;
	a = c;
	str = (unsigned char *)s;
	while (str[i] != a)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)&str[i]);
}
