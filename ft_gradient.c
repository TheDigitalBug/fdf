/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:48:49 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 12:52:01 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_gradient_x(t_base *map, int i, int j, int current_x_y)
{
	t_rgb rgb;

	rgb.dif = abs(map->points2d[i][j].x - map->points2d[i][j + 1].x);
	rgb.pos = (current_x_y - map->points2d[i][j].x) / rgb.dif;
	(rgb.pos < 0) ? rgb.pos = -rgb.pos : 1;
	if (map->alt == 1)
	{
		rgb.r = map->points[i][j].alt_r + (int)(rgb.pos *
				(map->points[i][j + 1].alt_r - map->points[i][j].alt_r));
		rgb.g = map->points[i][j].alt_g + (int)(rgb.pos *
				(map->points[i][j + 1].alt_g - map->points[i][j].alt_g));
		rgb.b = map->points[i][j].alt_b + (int)(rgb.pos *
				(map->points[i][j + 1].alt_b - map->points[i][j].alt_b));
	}
	else
	{
		rgb.r = map->points[i][j].color_r + (int)(rgb.pos *
				(map->points[i][j + 1].color_r - map->points[i][j].color_r));
		rgb.g = map->points[i][j].color_g + (int)(rgb.pos *
				(map->points[i][j + 1].color_g - map->points[i][j].color_g));
		rgb.b = map->points[i][j].color_b + (int)(rgb.pos *
				(map->points[i][j + 1].color_b - map->points[i][j].color_b));
	}
	return (rgb.b + rgb.g * 16 * 16 + rgb.r * 16 * 16 * 16 * 16);
}

int	ft_gradient_y(t_base *map, int i, int j, int current_x_y)
{
	t_rgb rgb;

	rgb.dif = abs(map->points2d[i][j].y - map->points2d[i + 1][j].y);
	rgb.pos = (current_x_y - map->points2d[i][j].y) / rgb.dif;
	(rgb.pos < 0) ? rgb.pos = -rgb.pos : 1;
	if (map->alt == 1)
	{
		rgb.r = map->points[i][j].alt_r + (int)(rgb.pos *
				(map->points[i + 1][j].alt_r - map->points[i][j].alt_r));
		rgb.g = map->points[i][j].alt_g + (int)(rgb.pos *
				(map->points[i + 1][j].alt_g - map->points[i][j].alt_g));
		rgb.b = map->points[i][j].alt_b + (int)(rgb.pos *
				(map->points[i + 1][j].alt_b - map->points[i][j].alt_b));
	}
	else
	{
		rgb.r = map->points[i][j].color_r + (int)(rgb.pos *
				(map->points[i + 1][j].color_r - map->points[i][j].color_r));
		rgb.g = map->points[i][j].color_g + (int)(rgb.pos *
				(map->points[i + 1][j].color_g - map->points[i][j].color_g));
		rgb.b = map->points[i][j].color_b + (int)(rgb.pos *
				(map->points[i + 1][j].color_b - map->points[i][j].color_b));
	}
	return (rgb.b + rgb.g * 16 * 16 + rgb.r * 16 * 16 * 16 * 16);
}

int	ft_gradient_d(t_base *map, int i, int j, int current_x_y)
{
	t_rgb rgb;

	rgb.dif = sqrt(pow(map->points2d[i][j].y - map->points2d[i + 1][j + 1].y, 2)
			+ pow(map->points2d[i][j].x - map->points2d[i + 1][j + 1].x, 2));
	rgb.pos = ((current_x_y - map->points2d[i][j].y) * cos(45 * DEG)) / rgb.dif;
	(rgb.pos < 0) ? rgb.pos = -rgb.pos : 1;
	if (map->alt == 1)
	{
		rgb.r = map->points[i][j].alt_r + (int)(rgb.pos *
				(map->points[i + 1][j + 1].alt_r - map->points[i][j].alt_r));
		rgb.g = map->points[i][j].alt_g + (int)(rgb.pos *
				(map->points[i + 1][j + 1].alt_g - map->points[i][j].alt_g));
		rgb.b = map->points[i][j].alt_b + (int)(rgb.pos *
				(map->points[i + 1][j + 1].alt_b - map->points[i][j].alt_b));
	}
	else
	{
		rgb.r = map->points[i][j].color_r + (int)(rgb.pos *
			(map->points[i + 1][j + 1].color_r - map->points[i][j].color_r));
		rgb.g = map->points[i][j].color_g + (int)(rgb.pos *
			(map->points[i + 1][j + 1].color_g - map->points[i][j].color_g));
		rgb.b = map->points[i][j].color_b + (int)(rgb.pos *
			(map->points[i + 1][j + 1].color_b - map->points[i][j].color_b));
	}
	return (rgb.b + rgb.g * 16 * 16 + rgb.r * 16 * 16 * 16 * 16);
}
