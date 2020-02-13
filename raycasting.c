/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:47:50 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/13 15:53:16 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float	limit_angle(float angle)
{
	angle = remainderf(angle, TWO_PI);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	find_out_fist_intercept(t_struct *data, float ray_angle)
{
	data->y_intercept = floor(data->y / SQUARE_SIZE) * SQUARE_SIZE;
	data->y_intercept += data->is_ray_facing_down ? SQUARE_SIZE : 0;
	data->x_intercept = data->x + (data->y_intercept - data->y) / tan(ray_angle);
	data->dy = SQUARE_SIZE;
	data->dy *= data->is_ray_facing_up ? -1 : 1;
	data->dx = SQUARE_SIZE / tan(ray_angle);
	data->dx *= (data->is_ray_facing_left && data->dx > 0) ? -1 : 1;
	data->dx *= (data->is_ray_facing_right && data->dx < 0) ? -1 : 1;
}
void	horizontal_ray_intersection(float ray_angle, t_struct *data,
		int *found_horiz_wall_hit, int *horz_wall_content)
{
	float horiz_touch_x;
	float horiz_touch_y;
	float x_to_check;
	float y_to_check;
    find_out_fist_intercept(data, ray_angle);
	horiz_touch_x = data->x_intercept;
	horiz_touch_y = data->y_intercept;
	while (horiz_touch_x >= 0 && horiz_touch_x <= WINDOW_WIDTH &&
			horiz_touch_y >= 0 && horiz_touch_y <= WINDOW_HEIGHT)
	{
		x_to_check = horiz_touch_x;
		y_to_check = horiz_touch_y + (data->is_ray_facing_up ? -1 : 0);

		if (if_wall(x_to_check, y_to_check))
		{
			data->save_horiz_wall_hit_x = horiz_touch_x;
			data->save_horiz_wall_hit_y = horiz_touch_y;
			*horz_wall_content = map[(int)floor(y_to_check / SQUARE_SIZE)][(int)floor(x_to_check / SQUARE_SIZE)];
			*found_horiz_wall_hit = TRUE;
			break;
		}
		else
		{
			horiz_touch_x += data->dx;
			horiz_touch_y += data->dy;
		}
	}
}

void	vertical_ray_intersection(float ray_angle, t_struct *data, int *found_vert_wall_hit, int *vert_wall_content)
{
	float vert_touch_x;
	float vert_touch_y;
	vert_wall_content = 0;
	data->x_intercept = floor(data->x / SQUARE_SIZE) * SQUARE_SIZE;
	data->x_intercept += data->is_ray_facing_right ? SQUARE_SIZE : 0;
	data->y_intercept = data->y + (data->x_intercept - data->x) * tan(ray_angle);
	data->dx = SQUARE_SIZE;
	data->dx *= data->is_ray_facing_left ? -1 : 1;
	data->dy = SQUARE_SIZE * tan(ray_angle);
	data->dy *= (data->is_ray_facing_up && data->dy > 0) ? -1 : 1;
	data->dy *= (data->is_ray_facing_down && data->dy < 0) ? -1 : 1;
	vert_touch_x = data->x_intercept;
	vert_touch_y = data->y_intercept;
	while (vert_touch_x >= 0 && vert_touch_x <= WINDOW_WIDTH && vert_touch_y >= 0 && vert_touch_y <= WINDOW_HEIGHT)
	{
		float xToCheck = vert_touch_x + (data->is_ray_facing_left ? -1 : 0);
		float yToCheck = vert_touch_y;
		if (if_wall(xToCheck, yToCheck))
		{
			data->save_vert_wall_hit_x = vert_touch_x;
			data->save_vert_wall_hit_y = vert_touch_y;
			vert_wall_content = &(map[(int)floor(yToCheck / SQUARE_SIZE)][(int)floor(xToCheck / SQUARE_SIZE)]);
			*found_vert_wall_hit = TRUE;
			break;
		}
		else
		{
			vert_touch_x += data->dx;
			vert_touch_y += data->dy;
		}
	}
}
void	get_smalest_distance(t_struct *data, int found_horiz_wall_hit, int found_vert_wall_hit)
{
	data->horz_hit_distance = found_horiz_wall_hit
								  ? distance_between_points(data->x, data->y, data->save_horiz_wall_hit_x, data->save_horiz_wall_hit_y)
								  : MAX_INT;
	data->vert_hit_distance = found_vert_wall_hit
								  ? distance_between_points(data->x, data->y, data->save_vert_wall_hit_x, data->save_vert_wall_hit_y)
								  : MAX_INT;
}
