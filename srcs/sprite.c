/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:26:10 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/20 11:35:25 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static void	bubble_sort(t_struct *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < data->count_spt)
	{
		j = 0;
		while (j < data->count_spt - i && j + 1 < data->count_spt)
		{
			if (data->sprite[j].dis < data->sprite[j + 1].dis)
			{
				tmp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		draw_sprites(t_struct *data, float x_off,
		float y_off, int index)
{
	size_t		i;
	size_t		j;
	size_t		size;
	int			id;
	const int	e = SPRITE_SIZE * SPRITE_SIZE;

	i = 0;
	j = 0;
	id = 0;
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
			id = SPRITE_SIZE * (SPRITE_SIZE * j / size)
				+ (SPRITE_SIZE * i / size);
			id = id >= (e) ? (e - 1) : id;
			if (data->img_data_texture_sprite[id] != BLACK)
				ft_draw(data, x_off + i, y_off + j,
						data->img_data_texture_sprite[id]);
		}
	}
}

void		set_up_sprite(t_struct *data)
{
	float	spt_angle;
	int		i_spt;
	int		i;

	i = 0;
	i_spt = 0;

	while (i < data->count_spt)
	{
		data->sprite[i].dis = distance_between_points(data->x,
				data->y, data->sprite[i].x, data->sprite[i].y);
		i++;
	}
	bubble_sort(data);
	while (i_spt < data->count_spt)
	{
		spt_angle = atan2f(data->sprite[i_spt].y - data->y,
				data->sprite[i_spt].x - data->x);
		while (spt_angle - data->rotation_angle > M_PI)
			spt_angle -= 2 * M_PI;
		while (spt_angle - data->rotation_angle < -M_PI)
			spt_angle += 2 * M_PI;
		if (data->w_height > data->w_width)
			data->sprite[i_spt].size = ((float )data->w_height
					/ data->sprite[i_spt].dis) * SQUARE_SIZE;
		else
			data->sprite[i_spt].size = ((float )data->w_width
					/ data->sprite[i_spt].dis) * SQUARE_SIZE;
		data->sprite[i_spt].y_off = (float )data->w_height / 2
			- data->sprite[i_spt].size / 2;
		data->sprite[i_spt].x_off = ((DEG(spt_angle)
					- DEG(data->rotation_angle)) * data->w_width)
			/ SPRITE_SIZE + (((float )data->w_width / 2)
					- (data->sprite[i_spt].size / 2));
		draw_sprites(data, data->sprite[i_spt].x_off,
				data->sprite[i_spt].y_off, i_spt);
		i_spt++;
	}
}

void		initialize_sprite(t_struct *data)
{
	int i;
	int j;
	int i_spt;

	i = 0;
	j = 0;
	i_spt = 0;
	if (data->count_spt == 0)
		return;
	if (!(data->sprite = (t_sprite *)malloc(sizeof(t_sprite)
					* (data->count_spt))))
		return;
	while (i < data->n_lines)
	{
		j = 0;
		while (j < g_lines_length[i])
		{
			if (data->map[i][j] == '2')
			{
				data->sprite[i_spt].x = ((float )j + 0.5f) * SQUARE_SIZE;
				data->sprite[i_spt].y = ((float )i + 0.5f) * SQUARE_SIZE;
				i_spt++;
			}
			j++;
		}
		i++;
	}
}

