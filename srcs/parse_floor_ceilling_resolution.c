/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceilling_resolution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:23 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/20 13:50:57 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_colors_alignment(t_struct *data, char *buff)
{
	while (buff[data->pos] != ',')
	{
		if (!ft_isdigit(buff[data->pos]))
			error("Ceilling identifier values misalignment!\n");
		data->pos++;
	}
	return (buff[data->pos] == ',' && ft_isdigit(buff[data->pos + 1]));
}

void		get_resolution_values(t_struct *data, char *buff)
{
	if (data->found_r)
		error("duplicate resolution symbol\n");
	data->pos++;
	if (buff[data->pos] != ' ' || !ft_isdigit(buff[++data->pos]))
		error("Resolution identifier misalignment!\n");
	data->w_width = ft_atoi(&buff[data->pos++]);
	data->pos += skip_number(&buff[data->pos]);
	data->w_height = ft_atoi(&buff[data->pos]);
	data->get_to_map += 1;
	data->found_r = 1;
}

void		get_floor_values(t_struct *data, char *buff)
{
	if (data->found_f)
		error("duplicate floor symbol\n");
	data->pos++;
	if (buff[data->pos] != ' ' || !ft_isdigit(buff[++data->pos]))
		error("Floor identifier misalignment!\n");
	data->f_red = ft_atoi(&buff[data->pos++]);
	if (!check_colors_alignment(data, buff))
		error("Floor identifier values misalignment!\n");
	data->f_green = ft_atoi(&buff[data->pos + 1]);
	if (!check_colors_alignment(data, buff + 1))
		error("Floor identifier values misalignment!\n");
	data->f_blue = ft_atoi(&buff[data->pos + 2]);
	data->get_to_map += 1;
	data->found_f = 1;
}

void		get_ceilling_values(t_struct *data, char *buff)
{
	if (data->found_c)
		error("duplicate ceilling symbol\n");
	data->pos += 1;
	if (buff[data->pos] != ' ' || !ft_isdigit(buff[++data->pos]))
		error("Ceilling identifier misalignment!\n");
	data->c_red = ft_atoi(&buff[data->pos]);
	if (!check_colors_alignment(data, buff))
		error("Ceilling identifier values misalignment!\n");
	data->c_green = ft_atoi(&buff[data->pos + 1]);
	if (!check_colors_alignment(data, buff + 1))
		error("Ceilling identifier values misalignment!\n");
	data->c_blue = ft_atoi(&buff[data->pos + 2]);
	data->pos += 3;
	data->get_to_map += 1;
	data->found_c = 1;
}
