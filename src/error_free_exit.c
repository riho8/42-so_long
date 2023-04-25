#include "../so_long.h"

void free_map(t_map *map){
	int i;

	i=0;
	while(map->map_arr[i] != NULL){
		free(map->map_arr[i]);
		i++;
	}
	free(map->map_arr);
}

void	error_exit(char *str)
{	
	// if(map == 1)
	// 	free_map(map);
	// if(fd != -1)
	// 	close(fd);
	// if(win != NULL)
	// 	mlx_destroy_window(mlx, win);
	// if(img != NULL){
	// 	mlx_destroy_image(mlx, img->img);
	// 	free(img);
	// }
	// if(mlx != NULL){
	// 	mlx_destroy_display(mlx);
	// 	free(mlx);
	// }
	
	perror(str);
	exit(EXIT_FAILURE);
}
