/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:33 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/20 13:54:40 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	insert_and_check_element(t_struct *data,
		const char *buff, int i, int j)
{
	data->map[i][j] = buff[data->pos];
	if (is_not_valid_element(data, buff))
		error("Invalid map element");
	if (is_player(data, buff))
	{
		if (data->is_multi_player)
			error("Too many players provided!\n");
		data->i_player = i;
		data->j_player = j;
		init_player(data);
		data->is_multi_player = TRUE;
	}
	else if (is_sprite(data->map[i][j]))
		data->count_spt++;
}

int			count_lines(const char *buff)
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
	return (num_lines + 1);
}

int			line_length(const char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

void		fill_out_map(t_struct *data, char *buff)
{
	int i;
	int j;

	i = -1;
	data->n_lines = count_lines(&buff[data->pos]);
	g_lines_length = (int *)malloc((data->n_lines) * sizeof(int));
	data->map = (char **)malloc((data->n_lines) * sizeof(char *));
	while (buff[data->pos] != '\0' && ++i < data->n_lines)
	{
		data->l_length = line_length(&buff[data->pos]);
		g_lines_length[i] = data->l_length;
		data->map[i] = (char *)malloc(sizeof(char) * data->l_length);
		buff[data->pos] == '\n' ? (data->pos += 1) : data->pos;
		j = -1;
		while (++j < data->l_length && buff[data->pos] != '\n')
		{
			insert_and_check_element(data, buff, i, j);
			data->pos += 1;
		}
		data->pos += 1;
	}
	check_map(data);
}

void		initialize_file_struct(t_struct *data)
{
	data->pos = 0;
	data->get_to_map = 0;
	data->f_red = 0;
	data->f_green = 0;
	data->f_blue = 0;
	data->c_red = 0;
	data->c_green = 0;
	data->c_blue = 0;
	data->found_we = 0;
	data->found_ea = 0;
	data->found_so = 0;
	data->found_no = 0;
	data->found_sp = 0;
	data->found_r = 0;
	data->found_c = 0;
	data->found_f = 0;
	ft_memset(data->no, 0, 25);
	ft_memset(data->so, 0, 25);
	ft_memset(data->ea, 0, 25);
	ft_memset(data->we, 0, 25);
	ft_memset(data->sp, 0, 25);
}


/*
 * 100 -----> 1920
 * 30 ------>
 */