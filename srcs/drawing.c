/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:59:06 by ksean             #+#    #+#             */
/*   Updated: 2020/02/13 10:56:19 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line1(t_fdf *map, t_line *line)
{
	float dx;
	float dy;

	dx = line->x[1] - line->x[0];
	dy = line->y[1] - line->y[0];
	while ((int)(line->x[0] - line->x[1]) || (int)(line->y[0] - line->y[1]))
	{
		mlx_pixel_put(map->mlx, map->win, line->x[0], line->y[0],
		ft_color(line->z[0], line->z[1]));
		line->a += fabsf((dx)) /
		fabsf((dy));
		line->y[0] += line->sign[1];
		if (line->a > 1.0)
		{
			line->a -= 1.0;
			line->x[0] += line->sign[0];
		}
	}
}

void	ft_line(t_fdf *map, t_line *line)
{
	float dx;
	float dy;

	dx = line->x[1] - line->x[0];
	dy = line->y[1] - line->y[0];
	line->sign[0] = ((dx) < 0 ? -1.0 : 1.0);
	line->sign[1] = ((dy) < 0 ? -1.0 : 1.0);
	line->a = 0;
	if (fabsf(dx) >= fabsf(dy))
	{
		while ((int)(line->x[0] - line->x[1]) || (int)(line->y[0] - line->y[1]))
		{
			mlx_pixel_put(map->mlx, map->win, line->x[0], line->y[0],
			ft_color(line->z[0], line->z[1]));
			line->a += fabsf(dy) / fabsf(dx);
			line->x[0] += line->sign[0];
			if (line->a > 1.0)
			{
				line->a -= 1.0;
				line->y[0] += line->sign[1];
			}
		}
	}
	else
		ft_line1(map, line);
}

void	draw_line(t_fdf *map, t_line *line)
{
	line->x[0] = line->x1[0];
	line->y[0] = line->y1[0];
	line->x[1] = line->x1[1];
	line->y[1] = line->y1[1];
	line->z[0] = map->matrix[(int)line->y[0]][(int)line->x[0]];
	line->z[1] = map->matrix[(int)line->y[1]][(int)line->x[1]];
	ft_transform(map, &line->x[0], &line->y[0], &line->z[0]);
	ft_transform(map, &line->x[1], &line->y[1], &line->z[1]);
	ft_line(map, line);
}

void	draw(t_fdf *map)
{
	map->line.x1[0] = 0;
	map->line.y1[0] = 0;
	while (map->line.y1[0] < map->hi)
	{
		map->line.x1[0] = 0;
		while (map->line.x1[0] < map->wi)
		{
			if (map->line.x1[0] < map->wi - 1)
			{
				map->line.x1[1] = map->line.x1[0] + 1.0;
				map->line.y1[1] = map->line.y1[0];
				draw_line(map, &map->line);
			}
			if (map->line.y1[0] < map->hi - 1)
			{
				map->line.x1[1] = map->line.x1[0];
				map->line.y1[1] = map->line.y1[0] + 1.0;
				draw_line(map, &map->line);
			}
			map->line.x1[0]++;
		}
		map->line.y1[0]++;
	}
}
