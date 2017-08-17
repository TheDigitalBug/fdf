/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:54:50 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/20 19:11:07 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_final(t_base *map)
{
	int j;
	int i;

	ft_draw_info(map);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (j < map->columns - 1)
				ft_drawline_x(map, i, j);
			if (i < map->rows - 1)
				ft_drawline_y(map, i, j);
			if ((map->diag == 1) && (j < map->columns - 1) &&
					(i < map->rows - 1))
				ft_drawline_diagonal(map, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_pixel_put(t_base *map, int i, int j, t_bres b)
{
	if (map->grad == 1)
	{
		if (b.type_line == 'x')
			mlx_pixel_put(map->mlx, map->win, b.x + map->move_x, b.y +
					map->move_y, ft_gradient_x(map, i, j, b.x));
		else if (b.type_line == 'y')
			mlx_pixel_put(map->mlx, map->win, b.x + map->move_x, b.y +
					map->move_y, ft_gradient_y(map, i, j, b.y));
		else
			mlx_pixel_put(map->mlx, map->win, b.x + map->move_x, b.y +
					map->move_y, ft_gradient_d(map, i, j, b.y));
	}
	else if (map->alt == 1)
		mlx_pixel_put(map->mlx, map->win, b.x + map->move_x, b.y +
				map->move_y, map->points[i][j].color_alt);
	else
		mlx_pixel_put(map->mlx, map->win, b.x + map->move_x, b.y +
				map->move_y, map->points[i][j].color);
}

void		ft_drawline_y(t_base *map, int i, int j)
{
	t_bres	b;

	b.type_line = 'y';
	b.x = map->points2d[i][j].x;
	b.y = map->points2d[i][j].y;
	b.dx = abs(map->points2d[i + 1][j].x - map->points2d[i][j].x);
	b.dy = -abs(map->points2d[i + 1][j].y - map->points2d[i][j].y);
	b.sx = map->points2d[i][j].x < map->points2d[i + 1][j].x ? 1 : -1;
	b.sy = map->points2d[i][j].y < map->points2d[i + 1][j].y ? 1 : -1;
	b.d = b.dx + b.dy;
	while (b.x != map->points2d[i + 1][j].x || b.y != map->points2d[i + 1][j].y)
	{
		ft_pixel_put(map, i, j, b);
		b.d2 = 2 * b.d;
		if (b.d2 >= b.dy)
		{
			b.x = b.x + b.sx;
			b.d = b.d + b.dy;
		}
		if (b.d2 <= b.dx)
		{
			b.y = b.y + b.sy;
			b.d = b.d + b.dx;
		}
	}
}

void		ft_drawline_x(t_base *map, int i, int j)
{
	t_bres	b;

	b.type_line = 'x';
	b.x = map->points2d[i][j].x;
	b.y = map->points2d[i][j].y;
	b.dx = abs(map->points2d[i][j + 1].x - map->points2d[i][j].x);
	b.dy = -abs(map->points2d[i][j + 1].y - map->points2d[i][j].y);
	b.sx = map->points2d[i][j].x < map->points2d[i][j + 1].x ? 1 : -1;
	b.sy = map->points2d[i][j].y < map->points2d[i][j + 1].y ? 1 : -1;
	b.d = b.dx + b.dy;
	while (b.x != map->points2d[i][j + 1].x || b.y != map->points2d[i][j + 1].y)
	{
		ft_pixel_put(map, i, j, b);
		b.d2 = 2 * b.d;
		if (b.d2 >= b.dy)
		{
			b.x = b.x + b.sx;
			b.d = b.d + b.dy;
		}
		if (b.d2 <= b.dx)
		{
			b.y = b.y + b.sy;
			b.d = b.d + b.dx;
		}
	}
}

void		ft_drawline_diagonal(t_base *map, int i, int j)
{
	t_bres	b;

	b.type_line = 'd';
	b.x = map->points2d[i][j].x;
	b.y = map->points2d[i][j].y;
	b.dx = abs(map->points2d[i + 1][j + 1].x - map->points2d[i][j].x);
	b.dy = -abs(map->points2d[i + 1][j + 1].y - map->points2d[i][j].y);
	b.sx = map->points2d[i][j].x < map->points2d[i + 1][j + 1].x ? 1 : -1;
	b.sy = map->points2d[i][j].y < map->points2d[i + 1][j + 1].y ? 1 : -1;
	b.d = b.dx + b.dy;
	while (b.x != map->points2d[i + 1][j + 1].x ||
			b.y != map->points2d[i + 1][j + 1].y)
	{
		ft_pixel_put(map, i, j, b);
		b.d2 = 2 * b.d;
		if (b.d2 >= b.dy)
		{
			b.x = b.x + b.sx;
			b.d = b.d + b.dy;
		}
		(b.d2 <= b.dx) ? (b.y = b.y + b.sy) : 1;
		(b.d2 <= b.dx) ? (b.d = b.d + b.dx) : 1;
	}
}
