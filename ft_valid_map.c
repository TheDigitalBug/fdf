/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 12:18:38 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 15:32:18 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_len(char *argv, int fd, t_base *map, int i)
{
	char	*line;
	char	**tmp;
	int		j;
	int		*len;

	fd = open(argv, O_RDONLY);
	len = (int *)malloc(sizeof(*len) * map->rows);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[i] != NULL)
			len[j] = ++i;
		j++;
		i = 0;
		if (j == map->rows)
		{
			while (i < j)
				if (len[i++] / len[0] != 1)
					return (1);
		}
	}
	close(fd);
	return (0);
}

void	ft_invalid_map(t_base *map, char error)
{
	int col;
	int row;

	ft_count_mapsize("sorry", map, &col, &row);
	ft_make_org_map("sorry", map);
	ft_setdefault(map);
	ft_make_new_map(map);
	map->diag = 1;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	ft_draw_final(map);
	ft_draw_info(map);
	if (error == 'N')
		mlx_string_put(map->mlx, map->win, 350, 920, W,
				"ERROR : 'There is no map'");
	if (error == 'M')
		mlx_string_put(map->mlx, map->win, 340, 920, W,
				"ERROR : 'Put correct rectangular map'");
	write(1, "\x1b[31mERROR : 'Put correct map'\x1b[0m", 33);
	mlx_key_hook(map->win, ft_key, map);
	mlx_loop(map->mlx);
}
