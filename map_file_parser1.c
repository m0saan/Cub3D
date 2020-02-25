/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:29:13 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/24 18:29:15 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		count_lines(char *buff)
{
	int i;
	int num_lines;

	i = 0;
	num_lines = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			num_lines += 1;
		i++;
	}
	return (num_lines);
}

int		line_length(char *line)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ')
			length++;
		i++;
	}
	return (length);
}

int		check_boudded_map(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 14)
	{
		j = 0;
		while (j < 29)
		{
			if (data->map[i][0] != 1 || data->map[i][data->l_length - 1] != 1)
				return (0);
			if (data->map[0][j] != 1 || data->map[data->n_lines - 1][j] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		fill_out_map(t_struct *data, char *buff)
{
	int i;
	int j;

	i = -1;
	data->l_length = line_length(&buff[data->pos]);
	data->n_lines = count_lines(&buff[data->pos]);
	while (buff[data->pos] != '\0' && i++ < data->n_lines - 1)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->l_length);
		buff[data->pos] == '\n' ? (data->pos += 1) : data->pos;
		j = -1;
		while (j++ < data->l_length && buff[data->pos] != '\n')
		{
			buff[data->pos] == ' ' ? data->pos += 1 : data->pos;
			if (buff[data->pos] != '1' && buff[data->pos] != '0'
            && buff[data->pos] != '2' && buff[data->pos] != 'N' && buff[data->pos] != 'W'
			&& buff[data->pos] != 'E' && buff[data->pos] != 'S')
				return (0);
			data->map[i][j] = ft_atoi(&buff[data->pos]);
			data->pos += 1;
		}
	}
	if (!(check_boudded_map(data)))
		return (0);
	return (1);
}

void	initialize_file_struct(t_struct *data)
{
	data->pos = 0;
	data->get_to_map = 0;
	data->width = 0;
	data->height = 0;
	data->f_red = 0;
	data->f_green = 0;
	data->f_blue = 0;
	data->c_red = 0;
	data->c_green = 0;
	data->c_blue = 0;
	data->map = malloc(sizeof(int) * 30);
	ft_memset(data->path_to_the_north_texture, 0, 25);
	ft_memset(data->path_to_the_south_texture, 0, 25);
	ft_memset(data->path_to_the_east_texture, 0, 25);
	ft_memset(data->path_to_the_west_texture, 0, 25);
}