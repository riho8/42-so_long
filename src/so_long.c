#include "../so_long.h"

int main(int argc, char **argv){
	t_data data;

	data.mlx = NULL;
	data.win = NULL; 
	data.map_arr = NULL;

	if(argc != 2)
		error_exit("Error\nInvalid input\n",&data);

	//berファイル読み込み
	init_map(&data,argv);

	//map用意
	//!このmap用意はmainでやらないと、関数終わったら消去されちゃう
	data.map_arr = (char**)ft_calloc(data.row_count + 1, sizeof(char *));
	if(!data.map_arr)
		error_exit("Error\nMap calloc failed\n",&data);

	//map配列生成
	interpret_map(&data,argv[1]);
	//mapエラーチェック
	check_map(&data);

	//mlx初期化
	data.mlx = mlx_init();
	if(!data.mlx)
		error_exit("Error\nFailed to initialize mlx\n",&data);

	// window作る
	data.win = mlx_new_window(data.mlx,data.col_count*CELL_W,data.row_count*CELL_H,"so_long");
	if(!data.win)
		error_exit("Error\nFailed to create window\n",&data);
	
	//素材を読み込む
	init_image(&data);
	
	//hook
	set_hook(&data);

	mlx_loop(data.mlx);

	return 0;
}