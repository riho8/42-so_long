/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:20:26 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:20:26 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_data *data)
{
	free_map(data->map_arr);
	destroy_image(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_game(data);
	else if (keysym == XK_w || keysym == XK_Up)
		move_player(data, 'y', -1);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(data, 'y', 1);
	else if (keysym == XK_a || keysym == XK_Left)
		move_player(data, 'x', -1);
	else if (keysym == XK_d || keysym == XK_Right)
		move_player(data, 'x', 1);
	return (0);
}

void	set_hook(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, &close_game, data);
	mlx_expose_hook(data->win, &put_img, data);
}
