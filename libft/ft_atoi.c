/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:56:42 by ksean             #+#    #+#             */
/*   Updated: 2019/10/10 14:23:04 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					neg;

	res = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res > 9223372036854775807)
		return ((neg == -1) ? 0 : -1);
	else
		return ((int)(res * neg));
}
