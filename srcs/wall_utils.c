/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:29:23 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/26 10:40:39 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		*which_texture(const t_struct *data)
{
	if (!g_rays[data->i_wall_index].was_hit_vertical
			&& g_rays[data->i_wall_index].is_ray_facing_down)
		return (data->img_tex2);
	else if (!g_rays[data->i_wall_index].was_hit_vertical
			&& g_rays[data->i_wall_index].is_ray_facing_up)
		return (data->img_tex1);
	else if ((g_rays[data->i_wall_index].was_hit_vertical)
			&& g_rays[data->i_wall_index].is_ray_facing_left)
		return (data->img_tex3);
	else if ((g_rays[data->i_wall_index].was_hit_vertical)
			&& g_rays[data->i_wall_index].is_ray_facing_right)
		return (data->img_tex4);
	return (0);
}

float	calculate_y_offset(const t_struct *data, int y)
{
	const float wall_height_by_tow = data->wall_height * 0.5F;
	const float win_height_by_tow = data->w_height * 0.5F;

	return (((float)y + (wall_height_by_tow) - (win_height_by_tow))
		* ((float)TEX_WIDTH / data->wall_height));
}

void	draw_walls(t_struct *data, float y)
{
	while (y++ < data->bottom_pixel - 1)
		ft_ljodran(data, (int)y);
}

void	draw_floor(t_struct *data, int floor)
{
	while (floor++ < data->w_height - 1)
		ft_draw(data, data->i_wall_index, floor,
				create_rgb(data->f_red, data->c_green, data->c_blue));
}

void	draw_ceilling(t_struct *data, int ceilling)
{
	while (ceilling++ < (int)data->top_pixel)
		ft_draw(data, data->i_wall_index, ceilling,
				create_rgb(data->c_red, data->c_green, data->c_blue));
}
