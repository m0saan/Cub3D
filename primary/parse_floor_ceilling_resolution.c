/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceilling_resolution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:23 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/24 11:11:02 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	skip_spaces(t_struct *data, char *buff)
{
	if (buff[data->pos] == 'F' || buff[data->pos] == 'C')
		data->pos += 1;
	while (!ft_isdigit(buff[data->pos]))
	{
		if (buff[data->pos] != ' ')
			error("Invalid separator\n");
		data->pos++;
	}
}

int		skip_spaces_til_comma(t_struct *data, char *buff)
{
	if (buff[data->pos] == ',' && ft_isdigit(buff[data->pos + 1]))
	{
		data->pos++;
		return (TRUE);
	}
	while (buff[data->pos] != ',')
	{
		if (ft_isdigit(buff[data->pos + 1]))
			return (TRUE);
		if (buff[data->pos] != ' ')
			error("Error in color values\n");
		data->pos++;
	}
	data->pos++;
	if (ft_isdigit(buff[data->pos]))
		return (TRUE);
	else if (buff[data->pos] == ' ' || buff[data->pos + 1] == ' ')
		skip_spaces(data, buff);
	return (ft_isdigit(buff[data->pos]));
}

void	get_resolution_values(t_struct *data, char *buff)
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

void	get_floor_values(t_struct *data, char *buff)
{
	if (data->found_f)
		error("duplicate floor symbol\n");
	if (buff[data->pos + 1] != ' ')
		error("Floor identifier misalignment\n");
	skip_spaces(data, buff);
	data->f_red = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_red);
	if (!skip_spaces_til_comma(data, buff))
		error("Error in color values");
	data->f_green = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_green);
	if (!skip_spaces_til_comma(data, buff))
		error("Error in color values");
	data->f_blue = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_blue);
	data->get_to_map += 1;
	data->found_f = 1;
	if (!data->f_red || !data->f_green || !data->f_blue)
		error("missing color");
}

void	get_ceilling_values(t_struct *data, char *buff)
{
	if (data->found_c)
		error("duplicate ceilling symbol\n");
	data->pos += 1;
	if (buff[data->pos] != ' ')
		error("Ceilling identifier misalignment\n");
	skip_spaces(data, buff);
	data->c_red = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_red);
	if (!skip_spaces_til_comma(data, buff))
		error("Error in color values");
	data->c_green = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_green);
	if (!skip_spaces_til_comma(data, buff))
		error("Error in color values");
	data->c_blue = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_blue);
	data->get_to_map += 1;
	data->found_c = 1;
	if (!data->c_red || !data->c_green || !data->c_blue)
		error("missing color");
}
