/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:33:30 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 14:20:02 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	get_resolution_values(t_struct *data, char *buff)
{
	data->pos++;
	data->w_width = ft_atoi(&buff[data->pos++]);
	data->pos += skip_number(&buff[data->pos]);
	data->w_height = ft_atoi(&buff[data->pos]);
	data->get_to_map += 1;
}

void	get_floor_values(t_struct *data, char *buff)
{
	data->pos++;
	data->f_red = ft_atoi(&buff[data->pos++]);
	data->pos += skip_number(&buff[data->pos]);
	data->f_green = ft_atoi(&buff[data->pos + 1]);
	data->pos += skip_number(&buff[data->pos]);
	data->f_blue = ft_atoi(&buff[data->pos + 1]);
	data->get_to_map += 1;
}

void	get_ceilling_values(t_struct *data, char *buff)
{
	data->pos += 2;
	data->c_red = ft_atoi(&buff[data->pos]);
	data->pos += skip_number(&buff[data->pos]);
	data->c_green = ft_atoi(&buff[data->pos + 1]);
	data->pos += skip_number(&buff[data->pos]);
	data->c_blue = ft_atoi(&buff[data->pos + 1]);
	data->get_to_map += 1;
}
