/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:26:10 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 11:16:07 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	draw_sprites(t_struct *data, float x_off,
		float y_off, int index)
{
	size_t		i;
	size_t		j;
	size_t		size;
	int			id;

	i = 0;
	size = data->sprite[index].size;
	while (i++ < size)
	{
		if (x_off + i < 0 || x_off + i > (float)data->w_width)
			continue;
		if (g_rays[(int)(x_off + i)].distance <= data->sprite[index].dis)
			continue;
		j = 0;
		while (j++ < size)
		{
			if (y_off + j < 0 || y_off + j > (float)data->w_height)
				continue;
			id = get_color_id(i, j, size);
			if (data->img_data_texture_sprite[id] != BLACK)
				ft_draw(data, x_off + i, y_off + j,
						data->img_data_texture_sprite[id]);
		}
	}
}

void	set_up_sprite(t_struct *data)
{
	float	spt_angle;
	int		i_spt;
	int		i;

	i = 0;
	i_spt = 0;
	set_sprite_distance(data, &i);
	bubble_sort(data);
	while (i_spt < data->count_spt)
	{
		spt_angle = atan2f(data->sprite[i_spt].y - data->y,
				data->sprite[i_spt].x - data->x);
		normalize_sprite_angle(data, &spt_angle);
		normalize_sprite_size(data, &i_spt);
		data->sprite[i_spt].y_off = calc_sprite_y_offset(data, i_spt);
		data->sprite[i_spt].x_off = calc_sprite_x_offset(data, i_spt,
				spt_angle);
		draw_sprites(data, data->sprite[i_spt].x_off,
				data->sprite[i_spt].y_off, i_spt);
		i_spt++;
	}
}

void	initialize_sprite(t_struct *data)
{
	int i;
	int j;
	int i_spt;

	i = -1;
	i_spt = 0;
	if (data->count_spt <= 0)
		error("sprite error") ;
	if (!(data->sprite = (t_sprite *)malloc(sizeof(t_sprite)
					* (data->count_spt))))
		return ;
	while (++i < data->n_lines)
	{
		j = -1;
		while (++j < g_lines_length[i])
			if (is_sprite(data->map[i][j]))
				set_sprite_coordinates(data, &i_spt, i, j);
	}
}
