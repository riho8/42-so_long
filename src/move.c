#include "../so_long.h"

void collect_item(t_data *data)
{
	data->item_count++;
	printf("Collect %d item✅\n",data->item_count);
	data->map->map_arr[data->pos_y][data->pos_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->pos_x * CELL_W), (data->pos_y * CELL_H));
}

void move_player_y(t_data *data,int dir){
	if(data->map->map_arr[data->pos_y + dir][data->pos_x] != '1' && (data->map->map_arr[data->pos_y + dir][data->pos_x] != 'E')){
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		data->pos_y += dir;
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
	}
	else if(data->map->map_arr[data->pos_y + dir][data->pos_x] == 'E' && data->item_count != data->map->item_total)
		ft_putstr_fd("!Collect them all to clear the game!\n",1);
	else if(data->map->map_arr[data->pos_y + dir][data->pos_x] == 'E' && data->item_count == data->map->item_total)
			close_game(data);
}

void move_player_x(t_data *data,int dir){
	if(data->map->map_arr[data->pos_y][data->pos_x + dir] != '1' && (data->map->map_arr[data->pos_y][data->pos_x + dir] != 'E')){
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
		data->pos_x += dir;
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
	}
	else if(data->map->map_arr[data->pos_y][data->pos_x + dir] == 'E' && data->item_count != data->map->item_total)
		ft_putstr_fd("⚠️Collect them all to clear the game!\n",1);
	else if(data->map->map_arr[data->pos_y][data->pos_x + dir] == 'E' && data->item_count == data->map->item_total)
			close_game(data);
}


void move_player(t_data *data, char axis, int dir){
	if(axis == 'x')
		move_player_x(data, dir);
	else
		move_player_y(data, dir);

	if(data->map->map_arr[data->pos_y][data->pos_x] == 'C'){
		collect_item(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * CELL_W), (data->pos_y * CELL_H));
	}

	//画面の表示が完了するまでプログラムが待機し、画面の更新が完了すると次の処理に移行するようになります。これにより、ウィンドウに描画される内容が完全に表示されるようになります。(画面を強制同期)
	mlx_do_sync(data->mlx);
  
   //shellに表示
	printf("Total move: %d\n", ++data->step_count);//!ft_printfにする
}
