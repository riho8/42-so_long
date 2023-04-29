/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:54:05 by rsihmaok          #+#    #+#             */
/*   Updated: 2023/04/29 11:54:05 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_to_map(t_data *data, char *buffer, int i)
{
	data->map_arr[i] = ft_strjoin(
			data->map_arr[i], buffer);
	if (!data->map_arr[i])
	{
		free_map(data->map_arr);
		data->map_arr = NULL;
		error_exit("Error\nMap strjoin failed\n", data);
	}
}

void	interpret_map(t_data *data, char *file)
{
	int		fd;
	int		read_rtn;
	char	buffer[2];
	int		i;

	read_rtn = 1;
	buffer[1] = '\0';
	fd = open(file, O_RDONLY);
	i = 0;
	while (read_rtn == 1)
	{
		read_rtn = read(fd, buffer, 1);
		if (read_rtn == 0)
			break ;
		if (read_rtn == -1)
		{
			close(fd);
			error_exit("Error\nFailed to read file*2\n", data);
		}
		if (buffer[0] != '\n' && buffer[0] != '\0')
			add_to_map(data, buffer, i);
		else
			i++;
	}
	data->map_arr[i][data->col_count] = '\0';
	close(fd);
}
