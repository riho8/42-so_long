
#include "../so_long.h"

void	interpret_map(t_data *data, char *file)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	i = 0;
	bytes = 1;
	buffer[1] = '\0';

	fd = open(file, O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map_arr[i] =  ft_strjoin(data->map_arr[i],buffer);
		else
			i++;
	}
	close(fd);
}

int get_map_size(int fd,t_data *data){
	char buffer;
	int row_count;
	int col_count;
	int i;
    
	row_count = 0;
	col_count = -1;
	i = 0;
    while(read(fd, &buffer, 1) == 1) { // !read_rtn == -1のときの処理
        if(buffer == '\n') {
            row_count++;
            if(col_count == -1) 
				col_count = i;
			else if(i != col_count)
				return -1;
            i = 0;
        }
        else 
			i++;
    }
	
	data->col_count = col_count;
	data->row_count = row_count;
	return 0;
}


void init_map(t_data *data,char **argv){
	int fd;
	char *file;
	int len;

	file = argv[1];
	len = ft_strlen(file);
	fd = open(file,O_RDONLY);
	if(fd == -1)
		error_exit("Error\nFailed to open file: Check file name\n",data);
	if(len <= 4 || ft_strncmp(file + len - 4, ".ber",4) != 0){
		close(fd);
		error_exit("Error\nInvalid file format\n",data);
	}
	
	if(get_map_size(fd,data) == -1){
		close(fd);
		error_exit("Error\nInvalid map shape\n",data);
	}

	data->step_count= 0;
	data->item_count = 0;
	close(fd);
}
