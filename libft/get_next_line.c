/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:31:15 by ksean             #+#    #+#             */
/*   Updated: 2020/02/10 19:05:38 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_makestr(char **str)
{
	char	*s;
	char	*s2;
	char	*out;
	int		i;

	out = *str;
	i = 0;
	while (out[i] != '\n' && out[i] != '\0')
		i++;
	s = ft_strsub(out, 0, i);
	if (out[i] == '\n')
	{
		s2 = ft_strsub(out, (i + 1), ft_strlen(&(out[i + 1])));
		free(*str);
		*str = s2;
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (s);
}

static	int		ft_return(int ret, char **out)
{
	free(*out);
	*out = NULL;
	return ((ret < 0) ? -1 : 0);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*out[OPEN_MAX];
	char			*tmp;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE > 8200000)
		return (-1);
	if (out[fd] == NULL)
		out[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = out[fd];
		out[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (ret > 0 || ft_strlen(out[fd]))
	{
		*line = ft_makestr(&out[fd]);
		return (1);
	}
	return (ft_return(ret, &out[fd]));
}
