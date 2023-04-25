#include "../so_long.h"

int main(int argc, char **argv){
	t_data data;
	t_map map;

	if(argc != 2)
		error_exit("Error\nInvalid input\n");

	//berファイル読み込み
	init_map(&data,argv);

	//map用意
	data.map = &map;
	//!このmap用意はmainでやらないと、関数終わったら消去されちゃう
	map.map_arr = (char**)ft_calloc(data.row_count + 1, sizeof(char *));
	if(!map.map_arr)
		error_exit("Error\nCalloc failed\n");

	//map配列生成
	interpret_map(&map,argv[1]);
	//mapエラーチェック
	check_map(&map,&data);

	//mlx初期化
	data.mlx = mlx_init();
	if(!data.mlx)
		error_exit("Error\nFailed to initialize mlx\n");

	// window作る
	data.win = mlx_new_window(data.mlx,data.col_count*CELL_W,data.row_count*CELL_H,"so_long");
	if(!data.win)
		error_exit("Error\nFailed to create window\n");
	
	//素材を読み込む
	init_image(&data);
	
	//hook
	set_hook(&data);

	mlx_loop(data.mlx);

	// // mlx_destroy_window(data.mlx, data.win); //!mlx_hookと一緒に使うと,セグフォになる
	// mlx_destroy_display(data.mlx);
	// free(data.mlx);
	return 0;
}