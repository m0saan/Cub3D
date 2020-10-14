/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:35 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/15 14:54:37 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int key_pressed(int keycode, t_struct *data)
{
	if (keycode == 15)
		data->reset = data->reset == 0 ? 1 : 0;
	if (keycode == 257)
		data->shift = data->shift == 0 ? 1 : 0;
	if (keycode == 46)
		data->m = data->m == 0 ? 1 : 0;
	if (keycode == 4)
		data->h = data->h == 0 ? 1 : 0;
	if (keycode == 17)
		data->t = data->t == 0 ? 1 : 0;
	if (keycode == 53)
		ft_close(data);
	if (keycode == 126)
		data->walk_direction = 1;
	if (keycode == 125)
		data->walk_direction = -1;
	if (keycode == 124)
		data->turn_direction = 1;
	if (keycode == 123)
		data->turn_direction = -1;
	return (TRUE);
}

int key_released(int keycode, t_struct *data)
{
	if (keycode == 15)
		data->reset = data->reset == 1 ? 0 : 1;
	if (keycode == 257)
		data->shift = data->shift == 1 ? 0 : 1;
	if (keycode == 126)
		data->walk_direction = 0;
	if (keycode == 125)
		data->walk_direction = 0;
	if (keycode == 124)
		data->turn_direction = 0;
	if (keycode == 123)
		data->turn_direction = 0;
	return (TRUE);
}

int ft_close(void *param)
{
	(void)param;
	exit(0);
}

void init_player(t_struct *data)
{
	static int count = 0;
	data->x = (data->j + 0.5) * SQUARE_SIZE;
	data->y = (data->i + 0.5) * SQUARE_SIZE;
	data->orientation = data->map[data->i][data->j];
	count++;
	set_up_player(data, count);
}

void set_up_player(t_struct *data, int e)
{
	if (e != 1)
	{
		write(1, "Player error!\n", 14);
		exit(0);
	}
	if (data->orientation == 'N')
		data->rotation_angle = RAD(270);
	else if (data->orientation == 'W')
		data->rotation_angle = RAD(180);
	else if (data->orientation == 'S')
		data->rotation_angle = RAD(90);
	else if (data->orientation == 'E')
		data->rotation_angle = RAD(0);
}
