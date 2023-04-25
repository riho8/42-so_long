#include "../so_long.h"






/****************************************/
int handle_keypress(int keysym, t_data *data){
	if(keysym == XK_Escape)
		mlx_destroy_window(data->mlx,data->win);
	return 0;
}
int handle_no_event(void *data){
	(void)data;
	return 0;
}

int close_game(t_data *data){
	mlx_destroy_window(data->mlx,data->win);
	return(0);
}
int main(void){
	t_data data;

	// mlx作る
	data.mlx = mlx_init();
	if(data.mlx == NULL)
		return(MLX_ERROR);
	
	// window作る
	data.win = mlx_new_window(data.mlx,WINDOW_WIDTH,WINDOW_HEIGHT,"Hello");
	if(data.win == NULL){
		free(data.win);
		return(MLX_ERROR);
	}

	//hook

	//!これがないと、ESC/Xで画面は閉じるけどプログラム自体は終わらない
	mlx_loop_hook(data.mlx,&handle_no_event,&data);

	mlx_hook(data.win,KeyPress,KeyPressMask,&handle_keypress,&data);
	mlx_hook(data.win,DestroyNotify,NoEventMask,&close_game,&data);

	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return 0;
}

//TODO:******************************************************/


static void	ft_collect(t_data *data)
/* will collect the collectables
** will remove them from the map-struct as well as the screen */
{
	data->item_count++;
	data->map->map_arr[data->pos_y][data->pos_x] = '0';
  //backgroundimageに変更する
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
}


void move_player(t_data *data, char axis, int dir){
	  //backgroundを追加
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->pos_x * IMG_W), (data->pos_y * IMG_H));
  
  //y軸の変化 (dirはUP=-1,DOWN=1など指定されてる)
  //y軸 && 動いた先が壁でない && ドアがある場合は、プレイヤーがすべてのダイヤを集めているか、またはドアがある場所にはダイヤが存在しない（すでに集めた）場合に、プレイヤーが進むことができる
	if (axis == 'y' && data->map->map_arr[data->pos_y + 1 * dir][data->pos_x] != '1'
		&& (data->map->map_arr[data->pos_y + 1 * dir][data->pos_x] != 'E'
		|| data->item_count == data->map->item))
		data->pos_y = data->pos_y + 1 * dir;

  //x軸ver
	else if (axis == 'x' && data->map->map_arr[data->pos_y][data->pos_x + 1 * dir] != '1'
		&& (data->map->map_arr[data->pos_y][data->pos_x + 1 * dir] != 'E'
		|| data->item_count == data->map->item))
		data->pos_x = data->pos_x + 1 * dir;

  //y軸　&& 移動先が出口　&& まだ全部ダイヤを集めてない
	else if (axis == 'y' && data->map->map_arr[data->pos_y + 1 * dir][data->pos_x] == 'E'
		&& data->item_count != data->map->item)
		ft_putstr_fd("Collect all item before leaving\n",1);
  //x軸ver
	else if (axis == 'x' && data->map->map_arr[data->pos_y][data->pos_x + 1 * dir] == 'E'
		&& data->item_count != data->map->item)
		ft_putstr_fd("Collect all item before leaving\n",1);


  //もし動いた先がダイヤだったら、獲得する
	if (data->map->map_arr[data->pos_y][data->pos_x] == 'C')
		ft_collect(data);
  
	mlx_put_image_to_window(data->mlx, data->win, data->img->player,
			(data->pos_x * IMG_W), (data->pos_y * IMG_H));

  //画面の表示が完了するまでプログラムが待機し、画面の更新が完了すると次の処理に移行するようになります。これにより、ウィンドウに描画される内容が完全に表示されるようになります。(画面を強制同期)
	mlx_do_sync(data->mlx);
  
  //shellに表示
	printf("You moved %d times.\n", ++data->step_count);//!ft_printfにする
}

int handle_keypress(int keysym, t_data *data){
	if(keysym == XK_Escape)
		mlx_destroy_window(data->mlx,data->win);
	else if(keysym == XK_w || keysym == XK_Up)
		move_player(data,'y',-1);
	else if(keysym == XK_s || keysym == XK_Down)
		move_player(data,'y',1);
	else if(keysym == XK_a || keysym == XK_Left)
		move_player(data,'x',-1);
	else if(keysym == XK_d || keysym == XK_Right)
		move_player(data,'x',1);
	return 0;
}
int close_game(t_data *data){
	mlx_destroy_window(data->mlx,data->win);
	return(0);
}

void set_hook(t_data *data){
	// // //!これがないと、ESC/Xで画面は閉じるけどプログラム自体は終わらない
	// mlx_loop_hook(data->mlx,&render_next_frame,data);
	mlx_hook(data->win,KeyPress,KeyPressMask,&handle_keypress,data);
	mlx_hook(data->win,DestroyNotify,NoEventMask,&close_game,data);
}