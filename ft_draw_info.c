/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 17:36:41 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/20 15:42:31 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_info(t_base *map)
{
	mlx_string_put(map->mlx, map->win, 10, 10, 0xcccccc, "HOT KEYS [K]");
	mlx_string_put(map->mlx, map->win, 11, 11, W, "HOT KEYS [K]");
	if (map->hotkeys == 1)
	{
		mlx_string_put(map->mlx, map->win, 10, 40, W, "[UP][DOWN]  -X-axis");
		mlx_string_put(map->mlx, map->win, 10, 55, W, "[LEFT][RGHT]-Y-axis");
		mlx_string_put(map->mlx, map->win, 10, 70, W, "[<][>]      -Z-axis");
		mlx_string_put(map->mlx, map->win, 10, 85, W, "[+][-]      -zoom");
		mlx_string_put(map->mlx, map->win, 10, 100, W, "[PgUp][PgD] -up/dwn");
		mlx_string_put(map->mlx, map->win, 10, 115, W, "[HOME][END] -left/r");
		mlx_string_put(map->mlx, map->win, 10, 130, W, "[SPACE]     -default");
		mlx_string_put(map->mlx, map->win, 10, 145, W, "[ESC]       -exit");
		mlx_string_put(map->mlx, map->win, 10, 160, W, "[G]         -gradient");
		mlx_string_put(map->mlx, map->win, 10, 175, W, "[D]         -diagonal");
		mlx_string_put(map->mlx, map->win, 10, 190, W, "[X][Z]      -d/inc Z");
	}
}
