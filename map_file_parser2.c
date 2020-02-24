/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:33:30 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/24 18:33:34 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


void	get_resolution_values(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	(*pos)++;
	data->w_width = ft_atoi(&buff[(*pos)++]);
	(*pos) += skip_number(&buff[(*pos)]);
	data->w_height = ft_atoi(&buff[(*pos)]);
	(*get_to_map) += 1;
}

void	get_floor_values(t_struct *data, char *buff, int *pos, int *get_to_map)
{
	(*pos)++;
	data->f_red = ft_atoi(&buff[(*pos)++]);
	(*pos) += skip_number(&buff[(*pos)]);
	data->f_green = ft_atoi(&buff[(*pos) + 1]);
	(*pos) += skip_number(&buff[(*pos)]);
	data->f_blue = ft_atoi(&buff[(*pos) + 1]);
	(*get_to_map) += 1;
}

void	get_ceilling_values(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	(*pos) += 2;
	data->c_red = ft_atoi(&buff[(*pos)]);
	(*pos) += skip_number(&buff[(*pos)]);
	data->c_green = ft_atoi(&buff[(*pos) + 1]);
	(*pos) += skip_number(&buff[(*pos)]);
	data->c_blue = ft_atoi(&buff[(*pos) + 1]);
	(*get_to_map) += 1;
}

void	get_north_texture_path(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	int i;

	i = 0;
	while (buff[(*pos)] != '.' && buff[(*pos) + 1] != '/')
		(*pos)++;
	while (buff[(*pos)] != '\n')
	{
		data->path_to_the_north_texture[i] = buff[(*pos)];
		i++;
		(*pos)++;
	}
	(*get_to_map) += 1;
}

void	get_south_texture_path(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	int i;

	i = 0;
	while (buff[(*pos)] != '.' && buff[(*pos) + 1] != '/')
		(*pos)++;
	while (buff[(*pos)] != '\n')
	{
		data->path_to_the_south_texture[i] = buff[(*pos)];
		i++;
		(*pos)++;
	}
	(*get_to_map) += 1;
}
