/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:18:46 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:18:46 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx = NULL;
	data.win = NULL;
	data.img = NULL;
	data.map_arr = NULL;
	if (argc != 2)
		error_exit("Error\nInvalid input\n", &data);
	read_file(&data, argv);
	data.map_arr = (char **)ft_calloc(data.row_count + 1, sizeof(char *));
	if (!data.map_arr)
		error_exit("Error\nMap calloc failed\n", &data);
	interpret_map(&data, argv[1]);
	check_map(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		error_exit("Error\nFailed to initialize mlx\n", &data);
	data.win = mlx_new_window(data.mlx, data.col_count * CELL_W, data.row_count
			* CELL_H, "so_long");
	if (!data.win)
		error_exit("Error\nFailed to create window\n", &data);
	init_image(&data);
	set_hook(&data);
	mlx_loop(data.mlx);
	return (0);
}
