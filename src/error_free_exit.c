/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:58:56 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:58:56 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_clear(t_data *data)
{
	free_map(data->map_arr);
	destroy_image(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_printf("🎉Congulatulations!GAME CLEAR!🎉\n");
	exit(EXIT_SUCCESS);
}

void	destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->background);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->player);
	mlx_destroy_image(data->mlx, data->img->item);
	mlx_destroy_image(data->mlx, data->img->exit);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	error_exit(char *str, t_data *data)
{
	if (data->map_arr != NULL)
		free_map(data->map_arr);
	if (data->img != NULL)
		destroy_image(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
