/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceilling_resolution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:23 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/24 09:43:51 by moboustt         ###   ########.fr       */
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
			error("Invalid separator\n");
		data->pos++;
	}
	data->pos++;
	if (ft_isdigit(buff[data->pos]))
		return (TRUE);
	else if (buff[data->pos] == ' ' || buff[data->pos + 1] == ' ')
		skip_spaces(data, buff);
	return (TRUE);
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
	skip_spaces(data, buff);
	data->f_red = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->f_red);
	if (!skip_spaces_til_comma(data, buff))
		error("PPPPPPPP");
	data->f_green = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->f_green);
	if (!skip_spaces_til_comma(data, buff))
		error("PPPPPPPP");
	data->f_blue = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->f_blue);
	data->get_to_map += 1;
	data->found_f = 1;
}

void	get_ceilling_values(t_struct *data, char *buff)
{
	if (data->found_c)
		error("duplicate ceilling symbol\n");
	data->pos += 1;
	skip_spaces(data, buff);
	data->c_red = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->c_red);
	if (!skip_spaces_til_comma(data, buff))
		error("PPPPPPPP");
	data->c_green = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->c_green);
	if (!skip_spaces_til_comma(data, buff))
		error("PPPPPPPP");
	data->c_blue = ft_atoi(&buff[data->pos]);
	data->pos += intLen(data->c_blue);
	data->get_to_map += 1;
	data->found_c = 1;
}
