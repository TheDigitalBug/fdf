/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:22:25 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 15:33:07 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_base *map)
{
	free(map->points);
	free(map->points2d);
	free(map);
	exit(0);
}

void	ft_setdefault(t_base *map)
{
	map->alpha = 45 * DEG;
	map->beta = 0 * DEG;
	map->gamma = 35 * DEG;
	map->grad = 1;
	map->alt = 0;
	map->diag = 0;
	map->hotkeys = 0;
	map->move_x = 500;
	map->move_y = 500;
	map->zoom_z = 1;
	if ((800 / map->rows) < (800 / map->columns))
		map->scale = 800 / map->rows;
	else
		map->scale = 800 / map->columns;
}

int		main(int argc, char **argv)
{
	int		col;
	int		row;
	t_base	*map;

	if (argc != 2)
		return (write(1, "\x1B[31musage:\x1b[0m ./fdf source_file", 34));
	map = (t_base *)malloc(sizeof(t_base));
	ft_count_mapsize(argv[1], map, &col, &row);
	ft_make_org_map(argv[1], map);
	ft_setdefault(map);
	ft_make_new_map(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	ft_draw_final(map);
	ft_draw_info(map);
	mlx_key_hook(map->win, ft_key, map);
	mlx_loop(map->mlx);
	free(map);
	return (0);
}
