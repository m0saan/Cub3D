/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:27:32 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 12:01:13 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
int is_negative(int v)
{
    return v < 0;
}

void check_floor_ceilling_values(t_struct *data)
{
    if (is_negative(data->f_red) || is_negative(data->f_green) || is_negative(data->f_blue))
        error("color values cannot be negative\n");
    if (is_negative(data->c_red) || is_negative(data->c_green) || is_negative(data->c_blue))
        error("color values cannot be negative\n");
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

void	get_sprite_path(t_struct *data, char *buff)
{
    int i;

    i = 0;
    if (is_valid_texture(data, buff) != 2)
        error("Invalid texture path!\n");

    data->pos += 2;
	while (buff[data->pos] != '\n')
	{
		data->sp[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
}

int		parse(t_struct *data, char **av)
{
	int			fd;
	const int	len = 4096;
	char		*buff[len];

	ft_memset(buff, 0, len);
	initialize_file_struct(data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		error("No such file!\n");
	if (!check_textures_f_c_s_availibility((char *)buff))
		return (FALSE);
	if (!read_map(data, (char *)buff))
		return (FALSE);
	if (!check_read_values(data))
		return (FALSE);
	return (TRUE);
}
