#ifndef SO_LONG_H
#define SO_LONG_H

//include

#include <mlx.h>
#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>
#include "libft/libft.h"

//define
#define CELL_W 40
#define CELL_H 40

//struct
typedef struct s_img
{
	void *player;
	void *background;
	void *item;
	void *exit;
	void *wall;
}	t_img;

typedef struct s_data
{
	void *mlx;
	void *win;
	int col_count;
	int row_count;
	int pos_x;
	int pos_y;
	int step_count;
	int item_count;
	int item_total;
	char **map_arr;
	t_img *img;
}	t_data;


// so_long.c

//map.c
void init_map(t_data *data,char **argv);
int get_map_size(int fd,t_data *data);
void interpret_map(t_data *data, char *file);

//check_map.c
void check_map(t_data *data);
int count_target(char *str,char target);

//error_free_exit.c
void	error_exit(char *str,t_data *data);
void free_map(t_data *data);

//image.c
void init_image(t_data *data);
void	load_texture(t_data *data, void **img, char *path);
void	put_img(t_data *data);

//hook.c
int handle_keypress(int keysym, t_data *data);
int close_game(t_data *data);
void set_hook(t_data *data);

//move.c
void move_player(t_data *data, char axis, int dir);
void move_player_x(t_data *data,int dir);
void move_player_y(t_data *data,int dir);
void collect_item(t_data *data);

#endif