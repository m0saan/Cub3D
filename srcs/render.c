/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:16 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/18 14:36:44 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int update(t_struct *data)
{

	cast_rays(data);
	render_walls(data);
	move_player(data);
    if (g_screenshot) {
        screen(data);
        ft_close(data);
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (FALSE);
}

int move_player(t_struct *data)
{
	data->rotation_angle += (float ) data->turn_direction * data->turn_speed;
	data->move_step = (float ) data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x + cosf(data->rotation_angle) * data->move_step;
	data->updated_player_y = data->y + sinf(data->rotation_angle) * data->move_step;

	int x = calculate_index(data->updated_player_x);
	int y = calculate_index(data->updated_player_y);

	if (!valid_indices(data, x, y))
		return FALSE;

	if (!if_wall(data->updated_player_x, data->updated_player_y, data) && !is_sprite(data->map[y][x]))
	{
		data->x = data->updated_player_x;
		data->y = data->updated_player_y;
	}
	return (TRUE);
}
