/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:25:59 by ksean             #+#    #+#             */
/*   Updated: 2020/02/09 15:29:10 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_fdf *map, float *x1, float *y1)
{
	*x1 *= map->zoom;
	*y1 *= map->zoom;
}

void	iso(float *x, float *y, float z)
{
	float px;
	float py;

	px = *x;
	py = *y;
	*x = (px - py) * cos(0.523599);
	*y = ((px + py) * sin(0.523599)) - z;
}

void	rot(t_fdf *map, float *x, float *y, float *z)
{
	float pz;
	float py;
	float px;

	px = *x;
	pz = *z;
	py = *y;
	*x = px * cos(map->angle) - py * sin(map->angle);
	*y = px * sin(map->angle) + py * cos(map->angle);
}

void	ft_transform(t_fdf *map, float *x, float *y, float *z)
{
	if (map->projection)
	{
		rot(map, x, y, z);
		iso(x, y, *z);
	}
	ft_zoom(map, x, y);
	*x += map->shiftx;
	*y += map->shifty;
}
