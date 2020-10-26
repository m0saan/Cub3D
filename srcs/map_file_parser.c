/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:32:47 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/26 10:40:39 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_floor_ceilling_values(t_struct *data)
{
	const int max_color_value = 255;

	if (is_negative(data->f_red) || is_negative(data->f_green)
			|| is_negative(data->f_blue))
		error("color values cannot be negative\n");
	if (data->f_red > max_color_value || data->f_green > max_color_value
			|| data->f_blue > max_color_value)
		error("color values cannot exceed the value 255\n");
	if (is_negative(data->c_red) || is_negative(data->c_green)
			|| is_negative(data->c_blue))
		error("color values cannot be negative\n");
	if (data->c_red > max_color_value || data->c_green > max_color_value
			|| data->c_blue > max_color_value)
		error("color values cannot exceed the value 255\n");
}

int		read_map(t_struct *data, char *buff)
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
		else if ((buff[data->pos] == '1' || buff[data->pos] == ' ')
				&& data->get_to_map == 8)
			return (screw_this_norminette(data, buff));
		data->pos++;
	}
	return (TRUE);
}

int		check_textures_f_c_s_availibility(char *buff)
{
	size_t len;

	len = ft_strlen(buff);
	if (!(ft_strnstr(buff, "NO", len)) || !(ft_strnstr(buff, "SO", len))
			|| !(ft_strnstr(buff, "WE", len)) || !(ft_strnstr(buff, "EA", len)))
		error("Texture error!\n");
	if (!(ft_strchr((char *)buff, 'R'))
			|| !(ft_strchr((char *)buff, 'F'))
			|| !(ft_strchr((char *)buff, 'C'))
			|| !(ft_strchr((char *)buff, 'S')))
		error("Error : valuable informations are not involved!\n");
	return (TRUE);
}

int		check_read_values(t_struct *data)
{
	if (data->w_height == 0 || data->w_width == 0)
		error("Error : missing width or height\n");
	if (data->w_height < 0 || data->w_width < 0)
		error("Error : width or height cannot be negative\n");
	if (!data->no[0] || !data->so[0]
			|| !data->we[0] || !data->we[0])
		error("Error : wrong texture path\n");
	check_floor_ceilling_values(data);
	return (TRUE);
}

int		parse(t_struct *data, char **av)
{
	int			fd;
	const int	len = 12000;
	char		buff[len];

	ft_memset(buff, 0, len);
	initialize_file_struct(data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		error("No such file!\n");
	if (!check_textures_f_c_s_availibility((char *)buff))
		return (FALSE);
	if (!read_map(data, (char *)buff))
		return (FALSE);
	if (!data->is_multi_player)
		error("Nod awa Nod!\n");
	if (!check_read_values(data))
		return (FALSE);
	return (TRUE);
}
