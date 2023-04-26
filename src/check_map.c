#include "../so_long.h"

int count_target(char *str,char target){
	int count;
	int i;

	count =0;
	i=0;
	while(str[i] != '\0'){
		if(str[i] == target)
			count++;
		i++;
	}
	return count;
}

void check_map(t_data *data){
	int i;
	int player;
	int exit;
	int item;

	i=0;
	player = 0;
	exit = 0;
	item = 0;
	printf("%d\n",data->col_count);
	while(data->map_arr && data->map_arr[i]){
		if((i == 0 || i == data->row_count- 1) && count_target(data->map_arr[i],'1') != data->col_count)
				error_exit("Error\nSurround map by walls!\n",data);
		if(data->map_arr[i][0] != '1' || data->map_arr[i][data->col_count-1] != '1')
			error_exit("Error\nSurround map by walls!\n",data);
		player += count_target(data->map_arr[i],'P');
		exit += count_target(data->map_arr[i],'E');
		item += count_target(data->map_arr[i],'C');
		i++;
	}
	if(player != 1 || exit != 1 || item < 1)
		error_exit("Error\nCheck number of components: player, exit, collectible\n",data);

	data->item_total = item;
}
