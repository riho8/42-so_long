#include "../so_long.h"

// void put_background(t_data *data){
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while (y < data->row_count)
// 	{
// 		while (x < data->col_count)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win,data->img->background, x*40, y*40);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }

void	put_img(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->row_count)
	{
		x=0;
		while(x < data->col_count){
			if (data->map->map_arr[y][x] == 'P'){
				mlx_put_image_to_window(data->mlx, data->win,data->img->player, x*CELL_W, y*CELL_H);
				data->pos_x = x;
				data->pos_y = y;
			}
			else if (data->map->map_arr[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,data->img->wall, x*CELL_W, y*CELL_H);
			else if (data->map->map_arr[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,data->img->item, x*CELL_W, y*CELL_H);
			else if (data->map->map_arr[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,data->img->exit, x*CELL_W, y*CELL_H);
			x++;
		}
		y++;
	}
}


void	load_texture(t_data *data, void **img, char *path) //! **渡さないと直接値に代入できない
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!*img)
		error_exit("Error\nFailed to load xpm file\n");
	// mlx_destroy_image(data->mlx, *img);
}

void init_image(t_data *data)
{
	 
	data->img = malloc(sizeof(t_img));
    if (!data->img)
		error_exit("Error\nFailed to allocate memory\n");
	
	load_texture(data, &data->img->background,"textures/background.xpm");
	load_texture(data, &data->img->wall,"textures/wall.xpm");
	load_texture(data, &data->img->player,"textures/player.xpm");
	load_texture(data, &data->img->exit,"textures/exit.xpm");
	load_texture(data, &data->img->item,"textures/item.xpm");

	// put_background(data);
	put_img(data);
}
