#include "../so_long.h"

int close_game(t_data *data){
	free_map(data);
	mlx_destroy_window(data->mlx,data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("🎉Congulatulations!You WIN!🎉\n");
	exit(EXIT_SUCCESS);
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

void set_hook(t_data *data){
	// // //!これがないと、ESC/Xで画面は閉じるけどプログラム自体は終わらない
	// mlx_loop_hook(data->mlx,&render_next_frame,data);
	mlx_hook(data->win,KeyPress,KeyPressMask,&handle_keypress,data);
	mlx_hook(data->win,DestroyNotify,NoEventMask,&close_game,data);
}