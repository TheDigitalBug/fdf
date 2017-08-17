/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:42:21 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/19 15:54:26 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** read color from file. devide to r, g, b. if there are no color - set #FFDB00
*/

int			ft_putcolor(char *tmp, t_base *map, int i, int j)
{
	int k;
	int	color;

	k = 0;
	while (tmp[k] != '\0')
	{
		if (tmp[k] == '0' && tmp[k + 1] == 'x')
		{
			color = ft_atoi_base(tmp + k + 2, 16);
			map->points[i][j].color_r = ((color >> 16) & 0xFF);
			map->points[i][j].color_g = ((color >> 8) & 0xFF);
			map->points[i][j].color_b = ((color) & 0xFF);
			return (color);
		}
		k++;
	}
	map->points[i][j].color_r = 255;
	map->points[i][j].color_g = 219;
	map->points[i][j].color_b = 0;
	return (16767744);
}

static int	ft_altcolor(t_base *map, int i, int j, int k)
{
	static int	color[8];

	color[0] = 205;
	color[1] = 255;
	color[2] = 2003199;
	color[3] = 3329330;
	color[4] = 2263842;
	color[5] = 9127718;
	color[6] = 13461561;
	color[7] = 16775930;
	map->points[i][j].alt_r = ((color[k] >> 16) & 0xFF);
	map->points[i][j].alt_g = ((color[k] >> 8) & 0xFF);
	map->points[i][j].alt_b = ((color[k]) & 0xFF);
	return (color[k]);
}

void		ft_color_atlitude(t_base *map, int i, int j)
{
	float dif;

	(map->max > 0 && map->min > 0) ? dif = (float)(map->max - map->min) / 8 : 1;
	(map->max >= 0 && map->min <= 0) ? dif =
		(float)(map->max - (-map->min)) / 8 : 1;
	(map->max < 0 && map->min < 0) ? dif =
		(float)(-(map->max - map->min)) / 8 : 1;
	if (map->points[i][j].z < -2 * dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 0);
	if (map->points[i][j].z < -dif && map->points[i][j].z >= -2 * dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 1);
	if (map->points[i][j].z < 0 && map->points[i][j].z >= -dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 2);
	if (map->points[i][j].z == 0)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 3);
	if (map->points[i][j].z > 0 && map->points[i][j].z <= dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 4);
	if (map->points[i][j].z > dif && map->points[i][j].z <= 2 * dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 5);
	if (map->points[i][j].z > 2 * dif && map->points[i][j].z <= 3 * dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 6);
	if (map->points[i][j].z > 3 * dif)
		map->points[i][j].color_alt = ft_altcolor(map, i, j, 7);
}
