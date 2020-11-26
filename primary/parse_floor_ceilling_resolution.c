/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceilling_resolution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:23 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/26 13:33:43 by moboustt         ###   ########.fr       */
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
			error("\e[0;31m Invalid separator\n");
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
			error("\e[0;31m Error in color values\n");
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
		error("\e[0;31m duplicate resolution symbol\n");
	data->pos++;
	if (buff[data->pos] != ' ')
		error("\e[0;31m Resolution identifier misalignment\n");
	skip_spaces(data, buff);
	data->w_width = ft_atoi(&buff[data->pos]);
	data->pos += skip_number(&buff[data->pos]);
	data->w_height = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->w_height) + 1;
	check_after_given_infos(data, buff);
	data->get_to_map += 1;
	data->found_r = 1;
}

void	get_floor_values(t_struct *data, char *buff)
{
	if (data->found_f)
		error("\e[0;31m duplicate floor symbol\n");
	if (buff[data->pos + 1] != ' ')
		error("\e[0;31m Floor identifier misalignment\n");
	skip_spaces(data, buff);
	data->f_red = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_red);
	if (!skip_spaces_til_comma(data, buff))
		error("\e[0;31m Error in color values");
	data->f_green = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_green);
	if (!skip_spaces_til_comma(data, buff))
		error("\e[0;31m Error in color values");
	data->f_blue = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->f_blue);
	data->get_to_map += 1;
	data->found_f = 1;
	check_after_given_infos(data, buff);
	if (!data->f_red || !data->f_green || !data->f_blue)
		error("\e[0;31m missing color");
}

void	get_ceilling_values(t_struct *data, char *buff)
{
	if (data->found_c)
		error("\e[0;31m duplicate ceilling symbol\n");
	data->pos += 1;
	if (buff[data->pos] != ' ')
		error("\e[0;31m Ceilling identifier misalignment\n");
	skip_spaces(data, buff);
	data->c_red = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_red);
	if (!skip_spaces_til_comma(data, buff))
		error("\e[0;31m Error in color values");
	data->c_green = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_green);
	if (!skip_spaces_til_comma(data, buff))
		error("\e[0;31m Error in color values");
	data->c_blue = ft_atoi(&buff[data->pos]);
	data->pos += int_len(data->c_blue);
	data->get_to_map += 1;
	data->found_c = 1;
	check_after_given_infos(data, buff);
	if (!data->c_red || !data->c_green || !data->c_blue)
		error("\e[0;31m missing color");
}
