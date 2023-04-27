#include "../so_long.h"

void free_map(t_data *data){
	int i;

	i=0;
	while(data->map_arr[i] != NULL){
		free(data->map_arr[i]);
		i++;
	}
	free(data->map_arr);
}


void	error_exit(char *str,t_data *data)
{	
	if(data->map_arr != NULL)
		free_map(data);
	if(data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if(data->mlx != NULL){
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	
	ft_printf("%s",str);
	exit(EXIT_FAILURE);
}
