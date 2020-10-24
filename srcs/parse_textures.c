/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:18:42 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 14:20:17 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	get_western_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
	if (is_valid_texture(data, buff) != 3)
		error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n' && buff[(data->pos)] != ' ')
	{
		data->we[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

void	get_easter_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
	if (is_valid_texture(data, buff) != 3)
		error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n' && buff[(data->pos)] != ' ')
	{
		data->ea[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

void	get_north_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
	if (is_valid_texture(data, buff) != 3)
		error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n' && buff[(data->pos)] != ' ')
	{
		data->no[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
}

void	get_south_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
	if (is_valid_texture(data, buff) != 3)
		error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n' && buff[(data->pos)] != ' ')
	{
		data->so[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
}

void	get_sprite_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	if (is_valid_texture(data, buff) != 2)
		error("Invalid texture path!\n");
	data->pos += 2;
	while (buff[(data->pos)] != '\n' && buff[(data->pos)] != ' ')
	{
		data->sp[i] = buff[data->pos];
		i++;
		data->pos++;
	}
	data->get_to_map += 1;
}
