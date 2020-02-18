/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:15:16 by ksean             #+#    #+#             */
/*   Updated: 2019/10/08 20:05:26 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	size_t			len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	snew = (char *)malloc((len + 1) * sizeof(char));
	if (snew == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		snew[i] = f(i, s[i]);
		i++;
	}
	snew[len] = '\0';
	return (snew);
}
