/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:32:47 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/30 09:45:18 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_floor_ceilling_values(t_struct *data)
{
	const int max_color_value = 255;

	if (is_negative(data->f_red) || is_negative(data->f_green)
			|| is_negative(data->f_blue))
		error("\e[0;31m color values cannot be negative\n");
	if (data->f_red > max_color_value || data->f_green > max_color_value
			|| data->f_blue > max_color_value)
		error("\e[0;31m color values cannot exceed the value 255\n");
	if (is_negative(data->c_red) || is_negative(data->c_green)
			|| is_negative(data->c_blue))
		error("\e[0;31m color values cannot be negative\n");
	if (data->c_red > max_color_value || data->c_green > max_color_value
			|| data->c_blue > max_color_value)
		error("\e[0;31m color values cannot exceed the value 255\n");
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
			get_texture_path(data, buff, &data->found_no, data->no);
		else if (buff[data->pos] == 'S' && buff[data->pos + 1] == 'O')
			get_texture_path(data, buff, &data->found_so, data->so);
		else if (buff[data->pos] == 'W' && buff[data->pos + 1] == 'E')
			get_texture_path(data, buff, &data->found_we, data->we);
		else if (buff[data->pos] == 'E' && buff[data->pos + 1] == 'A')
			get_texture_path(data, buff, &data->found_ea, data->ea);
		else if (buff[data->pos] == 'S')
			get_sprite_path(data, buff);
		else if ((buff[data->pos] == '1' || buff[data->pos] == ' ')
				&& data->get_to_map == 8)
			return (screw_this_norminette(data, buff));
		not_valid_element(data, buff);
		data->pos++;
	}
	return (TRUE);
}

int		check_textures_f_c_s_availibility(char *buff, int last)
{
	size_t len;

	len = ft_strlen(buff);
	if (buff[last - 1] == '\n')
		error("\e[0;31m New line at the end of the map!\n");
	if (!(ft_strnstr(buff, "NO", len)) || !(ft_strnstr(buff, "SO", len))
			|| !(ft_strnstr(buff, "WE", len)) || !(ft_strnstr(buff, "EA", len)))
		error("\e[0;31m Texture error!\n");
	if (!(ft_strchr((char *)buff, 'R'))
			|| !(ft_strchr((char *)buff, 'F'))
			|| !(ft_strchr((char *)buff, 'C'))
			|| !(ft_strnstr(buff, "S ", len)))
		error("\e[0;31m Error : valuable informations are not involved!\n");
	return (TRUE);
}

int		check_read_values(t_struct *data)
{
	if (data->w_height > 1800)
		data->w_height = 1800;
	if (data->w_width > 3200)
		data->w_width = 3200;
	if (data->w_height == 0 || data->w_width == 0)
		error("\e[0;31m Error : missing width or height\n");
	if (data->w_height < 0 || data->w_width < 0)
		error("\e[0;31m Error : width or height cannot be negative\n");
	check_floor_ceilling_values(data);
	return (TRUE);
}

int		parse(t_struct *data, char **av)
{
	int			fd;
	const int	len = 12000;
	char		buff[len];
	int			last;

	last = 0;
	ft_memset(buff, 0, len);
	initialize_file_struct(data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (last = read(fd, buff, len)) <= 0)
		error("\e[0;31m No such file!\n");
	if (!check_textures_f_c_s_availibility((char *)buff, last - 1))
		return (FALSE);
	if (!read_map(data, (char *)buff))
		return (FALSE);
	if (!data->is_multi_player)
		error("\e[0;31m Nod awa Nod!\n");
	if (!check_read_values(data))
		return (FALSE);
	data->ui_bar_size = (15 * data->w_width) / 100;
	return (TRUE);
}
