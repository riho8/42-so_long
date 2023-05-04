/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/04/29 11:54:26 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:54:26 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	process_buffer(char buffer, int *row_count, int *col_count, int *i)
{
	if (buffer == '\n')
	{
		(*row_count)++;
		if (*col_count == -1)
			*col_count = *i;
		else if (*i != *col_count)
			return (-1);
		*i = 0;
		return (1);
	}
	else
		(*i)++;
	return (0);
}

int	read_and_count(int fd, t_data *data, int *row_count, int *col_count)
{
	char	buffer;
	int		i;
	int		read_rtn;
	int		result;

	i = 0;
	read_rtn = 1;
	result = 1;
	while (read_rtn == 1)
	{
		read_rtn = read(fd, &buffer, 1);
		if (read_rtn == -1)
		{
			close(fd);
			error_exit("Error\nFailed to read file*1!\n", data);
		}
		if (result != 1 && read_rtn == 0)
			(*row_count)++;
		if (read_rtn == 0)
			break ;
		result = process_buffer(buffer, row_count, col_count, &i);
		if (result == -1)
			return (-1);
	}
	return (0);
}

int	get_map_size(int fd, t_data *data)
{
	int	row_count;
	int	col_count;
	int	result;

	row_count = 0;
	col_count = -1;
	result = read_and_count(fd, data, &row_count, &col_count);
	if (result == -1)
		return (-1);
	data->col_count = col_count;
	data->row_count = row_count;
	return (0);
}

void	read_file(t_data *data, char **argv)
{
	int		fd;
	char	*file;
	int		len;

	file = argv[1];
	len = ft_strlen(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("Error\nFailed to open file: Check file name!\n", data);
	if (len < 10 || ft_strncmp(file + len - 4, ".ber", 4) != 0
		|| ft_strncmp(file + 5, ".ber", 4) == 0 || ft_strncmp(file + 5, "..ber",
			5) == 0)
	{
		close(fd);
		error_exit("Error\nInvalid file!\n", data);
	}
	if (get_map_size(fd, data) == -1)
	{
		close(fd);
		error_exit("Error\nInvalid map shape!\n", data);
	}
	data->step_count = 0;
	data->item_count = 0;
	close(fd);
}
