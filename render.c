/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:16 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/15 14:54:18 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	render_firt_time(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	move_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

int		update(t_struct *data, uint32_t *buff)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
	&data->size_line, &data->endian);
	cast_rays(data);
	move_player(data);
	render_walls(data);
	mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (TRUE);
}

void	line(t_struct *data, int x0, int y0, int x1, int y1)
{
	size_t	i;
	int		dx;
	int		dy;
	float	x;
	float	y;

	i = 0;
	dx = x1 - x0;
	dy = y1 - y0;
	data->steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	data->x_inc = dx / (float)data->steps;
	data->y_inc = dy / (float)data->steps;
	x = x0;
	y = y0;
	while (i++ <= data->steps)
	{
		ft_draw(data, x, y, 0xff1100);
		x += data->x_inc;
		y += data->y_inc;
	}
}

int		move_player(t_struct *data)
{
	data->rotation_angle += data->turn_direction * data->turn_speed;
	data->move_step = data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x
	+ cos(data->rotation_angle) * data->move_step;
	data->updated_player_y = data->y
	+ sin(data->rotation_angle) * data->move_step;
	if (!if_wall(data->updated_player_x, data->updated_player_y))
	{
		data->x = data->updated_player_x;
		data->y = data->updated_player_y;
	}
	return (TRUE);
}
