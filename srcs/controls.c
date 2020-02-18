/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:01:43 by ksean             #+#    #+#             */
/*   Updated: 2020/02/13 17:35:42 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_hook(int key, t_fdf *data)
{
	if (key == 53)
	{
		map_free(data);
		exit(0);
	}
	if (key == 34)
		data->projection = 1;
	if (key == 35)
		data->projection = 0;
	if (key == 43)
		data->angle += 0.0523599;
	if (key == 47)
		data->angle -= 0.0523599;
	if (key == 126)
		data->shifty -= 10;
	if (key == 125)
		data->shifty += 10;
	if (key == 123)
		data->shiftx -= 10;
	if (key == 124)
		data->shiftx += 10;
	data->angle += 0.0523599;
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

int		ft_mouse_hook(int key, int x, int y, t_fdf *data)
{
	x = 1;
	y = 1;
	if (key == 5)
		data->zoom++;
	if (key == 4 && data->zoom > 1)
		data->zoom--;
	mlx_clear_window(data->mlx, data->win);
	data->line.x[0] = 0;
	data->line.y[0] = 0;
	draw(data);
	return (0);
}

int		ft_close(t_fdf *data)
{
	map_free(data);
	exit(0);
}
