/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:12:55 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 12:12:55 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_closed(int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == 'Z')
		return (1);
	if (map[y][x] == 'E')
	{
		map[y][x] = 'Z';
		return (1);
	}
	return (0);
}

void	check_path(int x, int y, char **map)
{
	if (map[y][x] != 'P')
		map[y][x] = '2';
	if (is_closed(x - 1, y, map) && is_closed(x + 1, y, map) && is_closed(x, y
			- 1, map) && is_closed(x, y + 1, map))
		return ;
	if (!is_closed(x, y - 1, map))
		check_path(x, y - 1, map);
	if (!is_closed(x + 1, y, map))
		check_path(x + 1, y, map);
	if (!is_closed(x, y + 1, map))
		check_path(x, y + 1, map);
	if (!is_closed(x - 1, y, map))
		check_path(x - 1, y, map);
}

char	**create_copy_map(t_data *data)
{
	char	**map;
	int		y;

	map = (char **)ft_calloc(data->row_count + 1, sizeof(char *));
	if (!map)
		error_exit("Error\nMap calloc failed*1\n", data);
	y = 0;
	while (y < data->row_count)
	{
		map[y] = ft_calloc(data->col_count + 1, sizeof(char));
		if (!map[y])
		{
			free_map(map);
			error_exit("Error\nMap calloc failed*2\n", data);
		}
		ft_memcpy(map[y], data->map_arr[y], data->col_count);
		y++;
	}
	return (map);
}

void	is_playable(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = create_copy_map(data);
	check_path(data->pos_x, data->pos_y, map);
	y = 0;
	while (y < data->row_count)
	{
		x = 0;
		while (x < data->col_count)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map);
				error_exit("Error\nMap is not playable\n", data);
			}
			x++;
		}
		y++;
	}
	free_map(map);
}
