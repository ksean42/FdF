/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:49:44 by ksean             #+#    #+#             */
/*   Updated: 2020/02/10 17:57:24 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_free(t_fdf *map)
{
	int i;

	i = 0;
	while (i != map->hi)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
}

int		ft_color(int z1, int z2)
{
	if (z1 > 9 || z2 > 9)
		return (RED);
	if (z1 > 0 || z2 > 0)
		return (GREEN);
	else if (z1 < 0 || z2 < 0)
		return (BLUE);
	else if (z1 < -10 || z2 < -10)
		return (BLUE >> 16);
	return (WHITE);
}

void	ft_init(t_fdf *map)
{
	map->hi = 0;
	map->wi = 0;
	map->matrix = 0;
	map->zoom = 15;
	map->shiftx = 500;
	map->shifty = 200;
	map->angle = 0.523599;
	map->projection = 1;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1000, 1000, "FdF");
	map->line.y[0] = 0;
	map->line.x[0] = 0;
}

float	ft_max(float a, float b)
{
	return (((a) > (b) ? (a) : (b)));
}
