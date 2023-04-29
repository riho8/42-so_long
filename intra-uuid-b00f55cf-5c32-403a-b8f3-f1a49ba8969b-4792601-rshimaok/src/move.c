/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:19:38 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:19:38 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_item(t_data *data)
{
	data->item_count++;
	ft_printf("Collect %d item✅\n", data->item_count);
	data->map_arr[data->pos_y][data->pos_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->pos_x * CELL_W), (data->pos_y * CELL_H));
}

void	move_player_y(t_data *data, int dir)
{
	if (data->map_arr[data->pos_y + dir][data->pos_x] != '1'
		&& (data->map_arr[data->pos_y + dir][data->pos_x] != 'E'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		data->pos_y += dir;
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		ft_printf("Total move: %d\n", ++data->step_count);
	}
	else if (data->map_arr[data->pos_y + dir][data->pos_x] == 'E'
			&& data->item_count != data->item_total)
		ft_putstr_fd("Collect them all to clear the game⛔️\n", 1);
	else if (data->map_arr[data->pos_y + dir][data->pos_x] == 'E'
			&& data->item_count == data->item_total)
	{
		ft_printf("Total move: %d\n", ++data->step_count);
		game_clear(data);
	}
}

void	move_player_x(t_data *data, int dir)
{
	if (data->map_arr[data->pos_y][data->pos_x + dir] != '1'
		&& (data->map_arr[data->pos_y][data->pos_x + dir] != 'E'))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		data->pos_x += dir;
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		ft_printf("Total move: %d\n", ++data->step_count);
	}
	else if (data->map_arr[data->pos_y][data->pos_x + dir] == 'E'
			&& data->item_count != data->item_total)
		ft_putstr_fd("Collect them all to clear the game⛔️\n", 1);
	else if (data->map_arr[data->pos_y][data->pos_x + dir] == 'E'
			&& data->item_count == data->item_total)
	{
		ft_printf("Total move: %d\n", ++data->step_count);
		game_clear(data);
	}
}

void	move_player(t_data *data, char axis, int dir)
{
	if (axis == 'x')
		move_player_x(data, dir);
	else
		move_player_y(data, dir);
	if (data->map_arr[data->pos_y][data->pos_x] == 'C')
	{
		collect_item(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
	}
	mlx_do_sync(data->mlx);
}
