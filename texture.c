/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:47:43 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/13 15:47:56 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void texture_from_file(t_struct *data)
{
	int width;
	int height;
	char *txt_path;
	int *texture_img_data;

	width = 0;
	height = 0;
	txt_path = "./textures/stone.xpm";
	data->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, txt_path, &width, &height);
	data->img_data_texture = (int *)mlx_get_data_addr(data->xpm_ptr, &data->bpp_text, &data->size_line_text, &data->endian_text);
}
void texture(t_struct *data)
{
	int x;
	int y;
	int pos = 0;

	x = 0;
	y = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			pos = (TEX_WIDTH * y) + x;
			buff[pos] = (x % 8 && y % 8) ? 0x3c40c6 : 0x1e272e;
			y++;
		}
		x++;
	}
}
void	calculate_wall_projection(t_struct *data)
{
		data->corrected_dsitance = rays[data->i_wall_index]->distance * cos(rays[data->i_wall_index]->ray_angle - data->rotation_angle);
		data->distance_to_projection_plane = (WINDOW_WIDTH * 0.5) / tan(FOV_ANGLE / 2);
		data->wall_height = (SQUARE_SIZE / data->corrected_dsitance) * data->distance_to_projection_plane;
		data->top_pixel = (WINDOW_HEIGHT / 2) - (data->wall_height / 2);
		data->top_pixel = data->top_pixel < 0 ? 0 : data->top_pixel;
		data->bottom_pixel = (WINDOW_HEIGHT / 2) + (data->wall_height / 2);
		data->bottom_pixel = data->bottom_pixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : data->bottom_pixel;
}
void render_walls(t_struct *data)
{
	int pos = 0;
	int txt_offset_x = 0;
	int txt_offset_y = 0;
	int cielling = 0;
	float y = 0;
	texture_from_file(data);
	while (data->i_wall_index < NUM_RAYS)
	{
		y = data->top_pixel;
		txt_offset_x = (rays[data->i_wall_index]->was_hit_vertical) ? ((int)rays[data->i_wall_index]->wall_h_y % SQUARE_SIZE) : ((int)rays[data->i_wall_index]->wall_h_x % SQUARE_SIZE);
		while (cielling++ < data->top_pixel)
			ft_draw(data, data->i_wall_index, cielling, 0x87ceeb);
		while (y < data->bottom_pixel)
		{
			txt_offset_y = (y + (int)(data->wall_height / 2) - (WINDOW_HEIGHT / 2)) * ((float)TEX_WIDTH / (int)data->wall_height);
			pos = (TEX_WIDTH * txt_offset_y) + txt_offset_x;
			pos = (pos > TEX_HEIGHT * TEX_WIDTH) ? (TEX_WIDTH * TEX_HEIGHT) : pos;
			ft_draw(data, data->i_wall_index, y, data->img_data_texture[pos]);
			y++;
		}
		cielling = data->bottom_pixel;
		while (cielling < WINDOW_HEIGHT)
		{
			ft_draw(data, data->i_wall_index, cielling, 0xCDB99C);
			cielling++;
		}
		data->i_wall_index++;
	}
}
