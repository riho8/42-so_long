/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:40:54 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 12:40:54 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_target(char *str, char target)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == target)
			count++;
		i++;
	}
	return (count);
}

void	check_components(t_data *data, int y, t_component *component)
{
	int	x;

	x = 0;
	while (x < data->col_count)
	{
		if (!(data->map_arr[y][x] == '1' || data->map_arr[y][x] == '0'
				|| data->map_arr[y][x] == 'C' || data->map_arr[y][x] == 'E'
				|| data->map_arr[y][x] == 'P'))
			error_exit("Error\nInvalid character in map\n", data);
		if (data->map_arr[y][0] != '1' || data->map_arr[y][data->col_count
			- 1] != '1')
			error_exit("Error\nSurround map by walls*2\n", data);
		if (data->map_arr[y][x] == 'P')
		{
			data->pos_x = x;
			data->pos_y = y;
			component->player++;
		}
		else if (data->map_arr[y][x] == 'E')
			component->exit++;
		else if (data->map_arr[y][x] == 'C')
			component->item++;
		x++;
	}
}

void	check_map(t_data *data)
{
	int			y;
	t_component	component;

	y = 0;
	component.player = 0;
	component.exit = 0;
	component.item = 0;
	while (y < data->row_count)
	{
		if ((y == 0 || y == data->row_count - 1)
			&& count_target(data->map_arr[y], '1') != data->col_count)
			error_exit("Error\nSurround map by walls*1\n", data);
		check_components(data, y, &component);
		y++;
	}
	if (component.player != 1 || component.exit != 1 || component.item < 1)
		error_exit("Error\nCheck number of components(P,E,C etc)\n", data);
	data->item_total = component.item;
	is_playable(data);
}
