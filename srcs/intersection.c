/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/26 10:40:39 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_vert_ray_intercept(t_struct *data, float ray_angle)
{
	data->x_intercept = floorf(data->x / SQUARE_SIZE) * SQUARE_SIZE;
	data->x_intercept += data->is_ray_facing_right ? SQUARE_SIZE : 0;
	data->y_intercept = data->y + (data->x_intercept - data->x) *
		tanf(ray_angle);
	data->dx = SQUARE_SIZE;
	data->dx *= data->is_ray_facing_left ? -1 : 1;
	data->dy = SQUARE_SIZE * tanf(ray_angle);
	data->dy *= (data->is_ray_facing_up && data->dy > 0) ? -1 : 1;
	data->dy *= (data->is_ray_facing_down && data->dy < 0) ? -1 : 1;
	data->vert_touch_x = data->x_intercept;
	data->vert_touch_y = data->y_intercept;
}

void	calculate_horz_ray_intercept(t_struct *data, float ray_angle)
{
	data->y_intercept = floorf(data->y / SQUARE_SIZE) * SQUARE_SIZE;
	data->y_intercept += data->is_ray_facing_down ? SQUARE_SIZE : 0;
	data->x_intercept = data->x + (data->y_intercept - data->y) /
		tanf(ray_angle);
	data->dy = SQUARE_SIZE;
	data->dy *= data->is_ray_facing_up ? -1 : 1;
	data->dx = SQUARE_SIZE / tanf(ray_angle);
	data->dx *= (data->is_ray_facing_left && data->dx > 0) ? -1 : 1;
	data->dx *= (data->is_ray_facing_right && data->dx < 0) ? -1 : 1;
	data->horiz_touch_x = data->x_intercept;
	data->horiz_touch_y = data->y_intercept;
}

void	horizontal_ray_intersection(float ray_angle, t_struct *data,
		int *found_horiz_wall_hit)
{
	calculate_horz_ray_intercept(data, ray_angle);
	while (data->horiz_touch_x >= 0 && data->horiz_touch_y >= 0)
	{
		data->x_horz_to_check = data->horiz_touch_x;
		data->y_horz_to_check = data->horiz_touch_y
			+ (data->is_ray_facing_up ? -1 : 0);
		if (if_wall(data->x_horz_to_check, data->y_horz_to_check, data))
		{
			data->save_horiz_wall_hit_x = data->horiz_touch_x;
			data->save_horiz_wall_hit_y = data->horiz_touch_y;
			*found_horiz_wall_hit = TRUE;
			break ;
		}
		else
		{
			data->horiz_touch_x += data->dx;
			data->horiz_touch_y += data->dy;
		}
	}
}

void	vertical_ray_intersection(float ray_angle, t_struct *data,
		int *found_vert_wall_hit)
{
	calculate_vert_ray_intercept(data, ray_angle);
	while (data->vert_touch_x >= 0 && data->vert_touch_y >= 0)
	{
		data->x_vert_to_check = data->vert_touch_x
			+ (data->is_ray_facing_left ? -1 : 0);
		data->y_vert_to_check = data->vert_touch_y;
		if (if_wall(data->x_vert_to_check, data->y_vert_to_check, data))
		{
			data->save_vert_wall_hit_x = data->vert_touch_x;
			data->save_vert_wall_hit_y = data->vert_touch_y;
			*found_vert_wall_hit = TRUE;
			break ;
		}
		else
		{
			data->vert_touch_x += data->dx;
			data->vert_touch_y += data->dy;
		}
	}
}
