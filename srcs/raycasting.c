/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:09 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/15 14:54:11 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	get_smalest_distance(t_struct *data, int found_horiz_wall_hit,
int found_vert_wall_hit)
{
	data->horz_hit_distance = found_horiz_wall_hit ?
	distance_between_points(data->x, data->y,
			data->save_horiz_wall_hit_x, data->save_horiz_wall_hit_y)
	: MAX_INT;
	data->vert_hit_distance = found_vert_wall_hit ?
	distance_between_points(data->x, data->y,
	data->save_vert_wall_hit_x, data->save_vert_wall_hit_y) : MAX_INT;
}

void	fill_out_ray(int ray_id, t_struct *data, int vert_wall_content,
int horz_wall_content)
{
	int i;

	i = 0;
	if (data->vert_hit_distance < data->horz_hit_distance)
	{
		g_rays[ray_id].distance = data->vert_hit_distance;
		g_rays[ray_id].wall_h_x = data->save_vert_wall_hit_x;
		g_rays[ray_id].wall_h_y = data->save_vert_wall_hit_y;
		g_rays[ray_id].wall_h_content = vert_wall_content;
		g_rays[ray_id].was_hit_vertical = TRUE;
	}
	else
	{
		g_rays[ray_id].distance = data->horz_hit_distance;
		g_rays[ray_id].wall_h_x = data->save_horiz_wall_hit_x;
		g_rays[ray_id].wall_h_y = data->save_horiz_wall_hit_y;
		g_rays[ray_id].wall_h_content = horz_wall_content;
		g_rays[ray_id].was_hit_vertical = FALSE;
	}
	i++;
	g_rays[ray_id].ray_angle = data->ray_angle;
	g_rays[ray_id].is_ray_facing_down = data->is_ray_facing_down;
	g_rays[ray_id].is_ray_facing_up = data->is_ray_facing_up;
	g_rays[ray_id].is_ray_facing_left = data->is_ray_facing_left;
	g_rays[ray_id].is_ray_facing_right = data->is_ray_facing_right;
}

void	cast_single_ray(int ray_id, float ray_angle, t_struct *data)
{
	int found_horiz_wall_hit;
	int found_vert_wall_hit;
	int vert_wall_content;
	int horz_wall_content;

	found_horiz_wall_hit = FALSE;
	found_vert_wall_hit = FALSE;
	horz_wall_content = 0;
	vert_wall_content = 0;
	ray_angle = limit_angle(ray_angle);
	data->ray_angle = ray_angle;
	data->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	data->is_ray_facing_up = !(data->is_ray_facing_down);
	data->is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	data->is_ray_facing_left = !(data->is_ray_facing_right);
	horizontal_ray_intersection(ray_angle, data,
	&found_horiz_wall_hit, &horz_wall_content);
	vertical_ray_intersection(ray_angle, data,
	&found_vert_wall_hit, &vert_wall_content);
	get_smalest_distance(data, found_horiz_wall_hit, found_vert_wall_hit);
	fill_out_ray(ray_id, data, vert_wall_content, horz_wall_content);
}

void	calculate_vert_ray_intercept(t_struct *data, float ray_angle)
{
	data->x_intercept = floor(data->x / SQUARE_SIZE) * SQUARE_SIZE;
	data->x_intercept += data->is_ray_facing_right ? SQUARE_SIZE : 0;
	data->y_intercept = data->y + (data->x_intercept - data->x) *
	tan(ray_angle);
	data->dx = SQUARE_SIZE;
	data->dx *= data->is_ray_facing_left ? -1 : 1;
	data->dy = SQUARE_SIZE * tan(ray_angle);
	data->dy *= (data->is_ray_facing_up && data->dy > 0) ? -1 : 1;
	data->dy *= (data->is_ray_facing_down && data->dy < 0) ? -1 : 1;
	data->vert_touch_x = data->x_intercept;
	data->vert_touch_y = data->y_intercept;
}

void	calculate_horz_ray_intercept(t_struct *data, float ray_angle)
{
	data->y_intercept = floor(data->y / SQUARE_SIZE) * SQUARE_SIZE;
	data->y_intercept += data->is_ray_facing_down ? SQUARE_SIZE : 0;
	data->x_intercept = data->x + (data->y_intercept - data->y) /
	tan(ray_angle);
	data->dy = SQUARE_SIZE;
	data->dy *= data->is_ray_facing_up ? -1 : 1;
	data->dx = SQUARE_SIZE / tan(ray_angle);
	data->dx *= (data->is_ray_facing_left && data->dx > 0) ? -1 : 1;
	data->dx *= (data->is_ray_facing_right && data->dx < 0) ? -1 : 1;
	data->horiz_touch_x = data->x_intercept;
	data->horiz_touch_y = data->y_intercept;
}
