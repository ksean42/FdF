/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:17:54 by ksean             #+#    #+#             */
/*   Updated: 2020/02/10 17:52:32 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF

typedef struct	s_coords
{
	int		x1[2];
	int		y1[2];
	float	x[2];
	float	y[2];
	float	z[2];
	float	sign[2];
	float	a;
}				t_line;

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	int			**matrix;
	int			wi;
	int			hi;
	int			zoom;
	int			shiftx;
	int			shifty;
	double		angle;
	int			projection;
	t_line		line;
}				t_fdf;

void			ft_init(t_fdf *map);
int				ft_read(char *av, t_fdf *map);
int				ft_len(char *str);
int				*get_array(int wi, char *line);
int				get_matrix(t_fdf *map, int fd);
int				get_wh(t_fdf *map, int fd);

void			draw(t_fdf *map);
void			draw_line(t_fdf *map, t_line *line);
void			ft_line(t_fdf *map, t_line *line);
void			iso(float *x, float *y, float z);
void			rot(t_fdf *map, float *x, float *y, float *z);
void			ft_transform(t_fdf *map, float *x, float *y, float *z);
int				ft_color(int z1, int z2);
void			ft_zoom(t_fdf *map, float *x1, float *y1);
float			ft_max(float a, float b);

int				ft_mouse_hook(int key, int x, int y, t_fdf *data);
int				ft_key_hook(int key, t_fdf *data);
int				ft_close(t_fdf *data);

void			map_free(t_fdf *map);

#endif
