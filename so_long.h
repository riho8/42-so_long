/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:42:59 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 12:42:59 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//include
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <fcntl.h>
# include <stdlib.h>

//define
# define CELL_W 40
# define CELL_H 40

//struct
typedef struct s_component
{
	int		player;
	int		exit;
	int		item;
}			t_component;

typedef struct s_img
{
	void	*player;
	void	*background;
	void	*item;
	void	*exit;
	void	*wall;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		col_count;
	int		row_count;
	int		pos_x;
	int		pos_y;
	int		step_count;
	int		item_count;
	int		item_total;
	char	**map_arr;
	t_img	*img;
}			t_data;

//read_file.c
void		read_file(t_data *data, char **argv);
int			get_map_size(int fd, t_data *data);
int			read_and_count(int fd, t_data *data, int *row_count,
				int *col_count);
int			process_buffer(char buffer, int *row_count, int *col_count, int *i);

//init_map.c
void		interpret_map(t_data *data, char *file);
void		add_to_map(t_data *data, char *buffer, int i);

//check_map.c
void		check_map(t_data *data);
void		check_components(t_data *data, int y, t_component *component);
int			count_target(char *str, char target);

//check_map_utils.c
void		is_playable(t_data *data);
char		**create_copy_map(t_data *data);
void		check_path(int x, int y, char **map);
int			is_closed(int x, int y, char **map);

//image.c
void		init_image(t_data *data);
void		load_texture(t_data *data, void **img, char *path);
int			put_img(t_data *data);
void		put_img_2(t_data *data, int y);

//hook.c
void		set_hook(t_data *data);
int			handle_keypress(int keysym, t_data *data);
int			close_game(t_data *data);

//move.c
void		move_player(t_data *data, char axis, int dir);
void		move_player_x(t_data *data, int dir);
void		move_player_y(t_data *data, int dir);
void		collect_item(t_data *data);

//error_free_exit.c
void		error_exit(char *str, t_data *data);
void		free_map(char **map);
void		destroy_image(t_data *data);
void		game_clear(t_data *data);

#endif