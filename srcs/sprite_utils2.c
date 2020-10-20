/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:19:53 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/20 12:22:44 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	set_sprite_coordinates(t_struct *data, int *i_spt, int i, int j)
{
	data->sprite[*i_spt].x = ((float)j + 0.5f) * SQUARE_SIZE;
	data->sprite[*i_spt].y = ((float)i + 0.5f) * SQUARE_SIZE;
	(*i_spt)++;
}

void	set_sprite_distance(t_struct *data, int *i)
{
	while (*i < data->count_spt)
	{
		data->sprite[*i].dis = distance_between_points(data->x, data->y,
				data->sprite[*i].x, data->sprite[*i].y);
		(*i)++;
	}
}

float	calc_sprite_y_offset(t_struct *data, int i_spt)
{
	return (float)data->w_height / 2 - data->sprite[i_spt].size / 2;
}

float	calc_sprite_x_offset(t_struct *data, int i_spt, float spt_angle)
{
	return (((DEG(spt_angle) - DEG(data->rotation_angle)) * data->w_width)
		/ SPRITE_SIZE + (((float)data->w_width / 2)
		- (data->sprite[i_spt].size / 2)));
}
