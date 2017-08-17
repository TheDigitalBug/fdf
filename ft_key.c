/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:02:21 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 14:15:01 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Key  53 - ESC
**	Key   2 - [D] - diagonal
**	Key   0 - [A] - altitude color
**	Key   5 - [G] - gradient color
**	Key  40 - [K] - hot keys
*/

static void	ft_key_body(int keycode, t_base *map)
{
	if (keycode == 40)
	{
		if (map->hotkeys == 1)
			map->hotkeys = 0;
		else
			map->hotkeys = 1;
	}
	(keycode == 6) ? (map->zoom_z = map->zoom_z + 0.1) : 1;
	(keycode == 7) ? (map->zoom_z = map->zoom_z - 0.1) : 1;
	(keycode == 125) ? (map->alpha = map->alpha - 2 * DEG) : 1;
	(keycode == 126) ? (map->alpha = map->alpha + 2 * DEG) : 1;
	(keycode == 123) ? (map->beta = map->beta + 2 * DEG) : 1;
	(keycode == 124) ? (map->beta = map->beta - 2 * DEG) : 1;
	(keycode == 43) ? (map->gamma = map->gamma + 2 * DEG) : 1;
	(keycode == 47) ? (map->gamma = map->gamma - 2 * DEG) : 1;
	(keycode == 119) ? (map->move_x = map->move_x + 5) : 1;
	(keycode == 115) ? (map->move_x = map->move_x - 5) : 1;
	(keycode == 121) ? (map->move_y = map->move_y + 5) : 1;
	(keycode == 116) ? (map->move_y = map->move_y - 5) : 1;
	(keycode == 69) ? (map->scale = map->scale + 1) : 1;
	(keycode == 78) ? (map->scale = map->scale - 1) : 1;
	(map->scale < 0) ? map->scale = 0 : 1;
	mlx_clear_window(map->mlx, map->win);
	ft_make_new_map(map);
	ft_draw_final(map);
}

int			ft_key(int keycode, t_base *map)
{
	(keycode == 53) ? ft_free(map) : 1;
	(keycode == 49) ? ft_setdefault(map) : 1;
	if (keycode == 2)
	{
		if (map->diag == 1)
			map->diag = 0;
		else
			map->diag = 1;
	}
	if (keycode == 0)
	{
		if (map->alt == 1)
			map->alt = 0;
		else
			map->alt = 1;
	}
	if (keycode == 5)
	{
		if (map->grad == 1)
			map->grad = 0;
		else
			map->grad = 1;
	}
	ft_key_body(keycode, map);
	return (0);
}
