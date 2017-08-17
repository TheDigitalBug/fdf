/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:02:42 by kkotliar          #+#    #+#             */
/*   Updated: 2017/02/22 15:32:49 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Count size of map :Columns and Rows. Malloc **points
*/

static void	ft_find_max(t_base *map)
{
	int i;
	int j;

	i = 0;
	map->max = map->points[0][0].z;
	map->min = map->points[0][0].z;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->max < map->points[i][j].z)
				map->max = map->points[i][j].z;
			if (map->min > map->points[i][j].z)
				map->min = map->points[i][j].z;
			j++;
		}
		i++;
	}
}

void		ft_count_mapsize(char *argv, t_base *map, int *col, int *row)
{
	int		j;
	int		fd;
	char	*line;
	char	**tmp;

	j = 0;
	*col = 0;
	*row = 1;
	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	(!(tmp = ft_strsplit(line, ' '))) ? ft_invalid_map(map, 'N') : 1;
	while (tmp[*col] != NULL)
		(*col)++;
	while (get_next_line(fd, &line) > 0)
		(*row)++;
	map->points2d = (t_pos **)malloc(sizeof(t_pos *) * (*row));
	map->points = (t_pos **)malloc(sizeof(t_pos *) * (*row));
	while (j < *row)
	{
		map->points[j] = (t_pos *)malloc(sizeof(t_pos) * (*col));
		map->points2d[j++] = (t_pos *)malloc(sizeof(t_pos) * (*col));
	}
	map->rows = *row;
	map->columns = *col;
	close(fd);
}

void		ft_make_org_map(char *argv, t_base *map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**tmp;

	i = 0;
	fd = open(argv, O_RDONLY);
	(ft_check_len(argv, fd, map, i) == 1) ? ft_invalid_map(map, 'M') : 1;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		j = 0;
		while (j < map->columns)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].z = ft_atoi(tmp[j]);
			map->points[i][j].color = ft_putcolor(tmp[j], map, i, j);
			j++;
		}
		i++;
	}
	ft_setdefault(map);
	ft_find_max(map);
}

static int	ft_count_new_x_y(t_base *map, int i, int j, char x_y)
{
	int ret;

	if (x_y == 'x')
	{
		ret = map->scale * (
		(map->points[i][j].x - map->columns / 2) * cos(map->beta) *
		cos(map->gamma) -
		(map->points[i][j].y - map->rows / 2) * sin(map->gamma) *
		cos(map->beta) -
		map->points[i][j].z * map->zoom_z * sin(map->beta));
	}
	else
	{
		ret = map->scale * (
		(map->points[i][j].x - map->columns / 2) * (-sin(map->alpha) *
		sin(map->beta) * cos(map->gamma) + cos(map->alpha) * sin(map->gamma)) +
		(map->points[i][j].y - map->rows / 2) * (sin(map->alpha) *
		sin(map->beta) * sin(map->gamma) + cos(map->alpha) * cos(map->gamma)) +
		map->points[i][j].z * map->zoom_z * (-sin(map->alpha)) *
		cos(map->beta));
	}
	return (ret);
}

void		ft_make_new_map(t_base *map)
{
	int			i;
	int			j;
	static int	flag = 0;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		map->points2d[i] = (t_pos *)malloc(sizeof(t_pos) * map->columns);
		while (j < map->columns)
		{
			map->points2d[i][j].x = ft_count_new_x_y(map, i, j, 'x');
			map->points2d[i][j].y = ft_count_new_x_y(map, i, j, 'y');
			if (flag == 0)
				ft_color_atlitude(map, i, j);
			j++;
		}
		i++;
	}
	flag = 1;
}
