/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:28:40 by ksean             #+#    #+#             */
/*   Updated: 2020/02/17 23:04:29 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_len(char *str)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	if (str[i] != ' ' && str[i])
		word++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

int	*get_array(int wi, char *line)
{
	int		*dest;
	char	**buf;
	int		i;

	i = 0;
	buf = ft_strsplit(line, ' ');
	if (!(dest = (int*)malloc(sizeof(int) * wi)))
		return (NULL);
	while (i != wi)
	{
		dest[i] = ft_atoi(buf[i]);
		i++;
	}
	i = 0;
	while (i != wi)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return (dest);
}

int	get_matrix(t_fdf *map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	if (!(map->matrix = (int**)malloc(sizeof(int*) * (map->hi + 1))))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		map->matrix[i] = get_array(map->wi, line);
		i++;
		free(line);
	}
	map->matrix[i] = NULL;
	return (1);
}

int	get_wh(t_fdf *map, int fd)
{
	int		h;
	int		w;
	int		l;
	int i;
	char	*line;

	h = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		l = ft_len(line);
		if (h == 0)
			w = l;
		if (w > l || l == 0)
		{
			close(fd);
			free(line);
			map_free(map);
			ft_putstr("Map is not valid\n");
			exit(0);
		}
		h++;
		free(line);
	}
	map->wi = w;
	map->hi = h;
	return (1);
}

int	ft_read(char *av, t_fdf *map)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putstr("open failed\n");
		map_free(map);
		exit(0);
	}
	get_wh(map, fd);
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putstr("open failed\n");
		map_free(map);
		exit(0);
	}
	get_matrix(map, fd);
	close(fd);
	return (1);
}
