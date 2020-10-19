/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:09 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/20 00:11:47 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	get_smallest_distance(t_struct *data, int found_horiz_wall_hit,
		int found_vert_wall_hit)
{
	data->horz_hit_distance = found_horiz_wall_hit
		? distance_between_points(data->x, data->y, data->save_horiz_wall_hit_x,
				data->save_horiz_wall_hit_y)
		: (float)MAX_INT;
	data->vert_hit_distance = found_vert_wall_hit
		? distance_between_points(data->x, data->y, data->save_vert_wall_hit_x,
				data->save_vert_wall_hit_y)
		: (float)MAX_INT;
}

void	fill_out_ray(int ray_id, t_struct *data)
{
	int i;

	i = 0;
	if (data->vert_hit_distance < data->horz_hit_distance)
	{
		g_rays[ray_id].distance = data->vert_hit_distance;
		g_rays[ray_id].wall_h_x = data->save_vert_wall_hit_x;
		g_rays[ray_id].wall_h_y = data->save_vert_wall_hit_y;
		g_rays[ray_id].was_hit_vertical = TRUE;
	}
	else
	{
		g_rays[ray_id].distance = data->horz_hit_distance;
		g_rays[ray_id].wall_h_x = data->save_horiz_wall_hit_x;
		g_rays[ray_id].wall_h_y = data->save_horiz_wall_hit_y;
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

	found_horiz_wall_hit = FALSE;
	found_vert_wall_hit = FALSE;
	ray_angle = limit_angle(ray_angle);
	data->ray_angle = ray_angle;
	data->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
	data->is_ray_facing_up = !(data->is_ray_facing_down);
	data->is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	data->is_ray_facing_left = !(data->is_ray_facing_right);
	horizontal_ray_intersection(ray_angle, data,
			&found_horiz_wall_hit);
	vertical_ray_intersection(ray_angle, data,
			&found_vert_wall_hit);
	get_smallest_distance(data, found_horiz_wall_hit, found_vert_wall_hit);
	fill_out_ray(ray_id, data);
}

void	cast_rays(t_struct *data)
{
	int		ray_id;
	float	ray_angle;

	ray_id = 0;
	ray_angle = data->rotation_angle - (FOV_ANGLE / 2);
	while (ray_id < data->w_width)
	{
		cast_single_ray(ray_id, ray_angle, data);
		ray_angle += FOV_ANGLE / (float)data->w_width;
		ray_id++;
	}
}
