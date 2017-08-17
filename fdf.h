/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:27:13 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 15:31:52 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define PI 3.1415926
# define DEG 0.0174532
# define W 0xffffff

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	float		pos;
	float		dif;
}				t_rgb;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			color_r;
	int			color_g;
	int			color_b;
	int			color_alt;
	int			alt_r;
	int			alt_g;
	int			alt_b;

}				t_pos;

typedef struct	s_base
{
	void		*mlx;
	void		*win;
	t_pos		**points;
	t_pos		**points2d;
	t_pos		**axis;
	t_pos		**axis2d;
	int			rows;
	int			columns;
	int			scale;
	int			move_x;
	int			move_y;
	float		alpha;
	float		beta;
	float		gamma;
	int			grad;
	int			diag;
	int			alt;
	float		zoom_z;
	int			hotkeys;
	int			max;
	int			min;
}				t_base;

typedef struct	s_bres
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			x;
	int			y;
	int			d;
	int			d2;
	char		type_line;
}				t_bres;

int				ft_key(int keycode, t_base *map);
void			ft_setdefault(t_base *map);
int				ft_putcolor(char *tmp, t_base *map, int i, int j);
int				ft_gradient_x(t_base *map, int i, int j, int current_x_y);
int				ft_gradient_y(t_base *map, int i, int j, int current_x_y);
int				ft_gradient_d(t_base *map, int i, int j, int current_x_y);
void			ft_draw_final(t_base *map);
void			ft_draw_info(t_base *map);
void			ft_drawline_x(t_base *map, int i, int j);
void			ft_drawline_y(t_base *map, int i, int j);
void			ft_drawline_diagonal(t_base *map, int i, int j);
int				ft_check_len(char *argv, int fd, t_base *map, int i);
void			ft_invalid_map(t_base *map, char error);
void			ft_count_mapsize(char *argv, t_base *map, int *col, int *row);
void			ft_make_org_map(char *argv, t_base *map);
void			ft_make_new_map(t_base *map);
void			ft_draw_info_rect(t_base *map);
void			ft_color_atlitude(t_base *map, int i, int j);
void			ft_free(t_base *map);

#endif
