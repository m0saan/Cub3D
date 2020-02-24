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

#include "cube3d.h"

void	get_western_texture_path(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	int i;

	i = 0;
	while (buff[(*pos)] != '.' && buff[(*pos) + 1] != '/')
		(*pos)++;
	while (buff[(*pos)] != '\n')
	{
		data->path_to_the_west_texture[i] = buff[(*pos)];
		i++;
		(*pos)++;
	}
	(*get_to_map) += 1;
}

void	get_easter_texture_path(t_struct *data, char *buff,
int *pos, int *get_to_map)
{
	int i;

	i = 0;
	while (buff[(*pos)] != '.' && buff[(*pos) + 1] != '/')
		(*pos)++;
	while (buff[(*pos)] != '\n')
	{
		data->path_to_the_east_texture[i] = buff[(*pos)];
		i++;
		(*pos)++;
	}
	(*get_to_map) += 1;
}

int		read_map(t_struct *data, char *buff)
{
	int pos;
	int get_to_map;

	pos = 0;
	get_to_map = 0;
	while (buff[pos])
	{
		if (buff[pos] == 'R')
			get_resolution_values(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'F')
			get_floor_values(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'C')
			get_ceilling_values(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'N' && buff[pos + 1] == 'O')
			get_north_texture_path(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'S' && buff[pos + 1] == 'O')
			get_south_texture_path(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'W' && buff[pos + 1] == 'E')
			get_western_texture_path(data, buff, &pos, &get_to_map);
		if (buff[pos] == 'E' && buff[pos + 1] == 'A')
			get_easter_texture_path(data, buff, &pos, &get_to_map);
		if (buff[pos] == '1' && buff[pos + 1] == ' '
		&& buff[pos + 2] == '1' && get_to_map == 7)
		{
			if (!(fill_out_map(data, &pos, buff)))
			{
				write(1, MAP_ERR, 18);
				return (1);
			}
			break ;
		}
		pos++;
	}
	return (0);
}

int		parse_2(t_struct *data, char **av)
{
	int		fd;
	int		len;
	char	*buff[len];

	len = 1024;
	ft_memset(buff, 0, len);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		return (0);
	if (!(ft_strchr((char *)buff, 'R')) || !(ft_strchr((char *)buff, 'F'))
	|| !(ft_strchr((char *)buff, 'C')) || !(ft_strchr((char *)buff, 'S')))
		return (1);
	if (read_map(data, (char *)buff))
		return (1);
	return (0);
}

int		parse_1(t_struct *data, char **av)
{
	initialize_file_struct(data);
	if (parse_2(data, av))
		return (1);
	return (0);
}
