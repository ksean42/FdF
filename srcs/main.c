/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:16:50 by ksean             #+#    #+#             */
/*   Updated: 2020/02/14 12:06:31 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf filename\n");
		return (0);
	}
	if (!(map = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	ft_init(map);
	ft_read(av[1], map);
	draw(map);
	mlx_hook(map->win, 2, 1L << 0, ft_key_hook, map);
	mlx_hook(map->win, 17, 1L << 0, ft_close, map);
	mlx_mouse_hook(map->win, ft_mouse_hook, map);
	mlx_loop(map->mlx);
	map_free(map);
	return (0);
}
