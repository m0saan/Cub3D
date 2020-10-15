/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:32 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/24 18:27:36 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int read_map(t_struct *data, char *buff)
{
	while (buff[data->pos])
	{
		if (buff[data->pos] == 'R')
			get_resolution_values(data, buff);
		else if (buff[data->pos] == 'F')
			get_floor_values(data, buff);
		else if (buff[data->pos] == 'C')
			get_ceilling_values(data, buff);
		else if (buff[data->pos] == 'N' && buff[data->pos + 1] == 'O')
			get_north_texture_path(data, buff);
		else if (buff[data->pos] == 'S' && buff[data->pos + 1] == 'O')
			get_south_texture_path(data, buff);
		else if (buff[data->pos] == 'W' && buff[data->pos + 1] == 'E')
			get_western_texture_path(data, buff);
		else if (buff[data->pos] == 'E' && buff[data->pos + 1] == 'A')
			get_easter_texture_path(data, buff);
		else if (buff[data->pos] == 'S' && buff[data->pos + 1] == ' ')
			get_sprite_path(data, buff);
		else if ((buff[data->pos] == '1' || buff[data->pos] == ' ') && data->get_to_map == 8)
			return (screw_this_norminette(data, buff)) ? 1 : 0;
		data->pos++;
	}
	return (0);
}

int check_textures_f_c_s_availibility(char *buff)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(buff);
	if (!(ft_strnstr(buff, "NO", len)) || !(ft_strnstr(buff, "SO", len)) || !(ft_strnstr(buff, "WE", len)) || !(ft_strnstr(buff, "EA", len)))
	{
		write(1, "Texture error!\n", 15);
		return (1);
	}
	if (!(ft_strchr((char *)buff, 'R')) || !(ft_strchr((char *)buff, 'F')) || !(ft_strchr((char *)buff, 'C')) || !(ft_strchr((char *)buff, 'S')))
	{
		write(1, "Error : valuable informations are not involved!\n", 48);
		return (1);
	}
	return (0);
}

int check_read_vaues(t_struct *data)
{
	if (data->w_height == 0 || data->w_width == 0)
	{
		write(1, "Error : missing width or height\n", 32);
		return (1);
	}
	if (data->no[0] == 0 || data->so[0] == 0 || data->we[0] == 0 || data->we[0] == 0)
	{
		write(1, "Error : wrong textute path\n", 27);
		return (1);
	}
	return (0);
}

void get_sprite_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	data->pos += 2;
	while (buff[data->pos] != '\n')
	{
		data->sp[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
}

int parse(t_struct *data, char **av)
{
	int fd;
	int len;
	len = 1024;
	char *buff[len];

	ft_memset(buff, 0, len);
	initialize_file_struct(data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
	{
		write(1, "No such file!\n", 14);
		return (1);
	}
	if (check_textures_f_c_s_availibility((char *)buff))
		return (1);
	if (read_map(data, (char *)buff))
		return (1);
	if (check_read_vaues(data))
		return (1);
	return (0);
}
