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

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
        size_t  i;
        size_t  j;

        j = 0;
        i = 0;
        if (*needle == '\0')
                return ((char *)haystack);
        while (i < len && haystack[i] != '\0')
        {
                while (haystack[i + j] == needle[j] && i + j < len)
                {
                        if (needle[j + 1] == '\0')
                                return ((char *)(haystack + i));
                        j++;
                }
                j = 0;
                i++;
        }
        return (0);
}
void	get_western_texture_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	while (buff[(data->pos)] != '.' && buff[(data->pos) + 1] != '/')
		(data->pos)++;
	while (buff[(data->pos)] != '\n')
	{
		data->path_to_the_west_texture[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

void	get_easter_texture_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	while (buff[(data->pos)] != '.' && buff[(data->pos) + 1] != '/')
		(data->pos)++;
	while (buff[(data->pos)] != '\n')
	{
		data->path_to_the_east_texture[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

int		screw_this_norminette(t_struct *data, char *buff)
{
	if (!(fill_out_map(data, buff)))
	{
		write(1, MAP_ERR, 18);
		return (1);
	}
	return (0);
}

int		read_map(t_struct *data, char *buff)
{
	while (buff[data->pos])
	{
		if (buff[data->pos] == 'R')
			get_resolution_values(data, buff);
		if (buff[data->pos] == 'F')
			get_floor_values(data, buff);
		if (buff[data->pos] == 'C')
			get_ceilling_values(data, buff);
		if (buff[data->pos] == 'N' && buff[data->pos + 1] == 'O')
			get_north_texture_path(data, buff);
		if (buff[data->pos] == 'S' && buff[data->pos + 1] == 'O')
			get_south_texture_path(data, buff);
		if (buff[data->pos] == 'W' && buff[data->pos + 1] == 'E')
			get_western_texture_path(data, buff);
		if (buff[data->pos] == 'E' && buff[data->pos + 1] == 'A')
			get_easter_texture_path(data, buff);
		if (buff[data->pos] == '1' && buff[data->pos + 1] == ' '
		&& buff[data->pos + 2] == '1' && data->get_to_map == 7)
		{
			screw_this_norminette(data, buff);
			break ;
		}
		data->pos++;
	}
	return (0);
}

int		check_textures_f_c_s_availibility(t_struct *data, char *buff)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(buff);
		if (!(ft_strnstr(buff, "NO", len)) || !(ft_strnstr(buff, "SO", len))
		|| !(ft_strnstr(buff, "WE", len)) || !(ft_strnstr(buff, "EA", len)))
		{
			write(1,"Texture error!\n", 15);
			return (1);
		}
		if (!(ft_strchr((char *)buff, 'R')) || !(ft_strchr((char *)buff, 'F'))
		|| !(ft_strchr((char *)buff, 'C')) || !(ft_strchr((char *)buff, 'S')))
		{
			write(1, "Error : valuable informations are not involved!\n", 48);
			return (1);
		}
	return (0);
}

int		check_read_vaues(t_struct *data)
{
	if (data->w_height == 0 || data->w_width == 0)
	{
		write(1, "Error : missing width or height\n", 32);
		return (1);
	}
	if (data->path_to_the_north_texture[0] == 0 || data->path_to_the_south_texture[0] == 0
	|| data->path_to_the_west_texture[0] == 0 || data->path_to_the_east_texture[0] == 0)
	{
		write(1, "Error : wrong textute path\n", 27);
		return (1);
	}
	return (0);
}
int		parse(t_struct *data, char **av)
{
	int		fd;
	int		len;
	char	*buff[len];

	len = 1024;
	ft_memset(buff, 0, len);
	initialize_file_struct(data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
	{
		write(1, "No such file!\n", 14);
		return (1);
	}
	if (check_textures_f_c_s_availibility(data, (char *)buff))
		return (1);
	if (read_map(data, (char *)buff))
		return (1);
	if (check_read_vaues(data))
		return 1;
	return (0);
}