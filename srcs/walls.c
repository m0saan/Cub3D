/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:01 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/18 12:15:16 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static float calculate_y_offset(const t_struct *data, int y);
static int calculate_x_offset(const t_struct *data);
static void draw_ceilling(t_struct *data, int ceilling);
static void draw_floor(t_struct *data, int floor);
static void draw_walls(t_struct *data, float y);
static int *which_texture(const t_struct *data);

static int is_not_valid_xpm(t_struct *data)
{
	return !data->xpm_ptr1 || !data->xpm_ptr2 || !data->xpm_ptr3 || !data->xpm_ptr4 || !data->sprite_xpm;
}

void texture_from_file(t_struct *data)
{
	int w;
	int h;

	data->xpm_ptr1 = mlx_xpm_file_to_image(data->mlx_ptr, data->no, &w, &h);
	data->xpm_ptr2 = mlx_xpm_file_to_image(data->mlx_ptr, data->so, &w, &h);
	data->xpm_ptr3 = mlx_xpm_file_to_image(data->mlx_ptr, data->we, &w, &h);
	data->xpm_ptr4 = mlx_xpm_file_to_image(data->mlx_ptr, data->ea, &w, &h);
	data->sprite_xpm = mlx_xpm_file_to_image(data->mlx_ptr, data->sp, &w, &h);
	if (is_not_valid_xpm(data))
	    error("Error : wrong texture path!\n");
	data->img_tex1 = (int *)mlx_get_data_addr(data->xpm_ptr1,
                                              &data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex2 = (int *)mlx_get_data_addr(data->xpm_ptr2,
                                              &data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex3 = (int *)mlx_get_data_addr(data->xpm_ptr3,
                                              &data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_tex4 = (int *)mlx_get_data_addr(data->xpm_ptr4,
                                              &data->bpp_text, &data->size_line_text, &data->endian_text);
	data->img_data_texture_sprite = (int *)mlx_get_data_addr(data->sprite_xpm,
															 &data->bpp_text, &data->size_line_text, &data->endian_text);
}

void calculate_wall_projection(t_struct *data)
{
	data->corrected_dsitance = g_rays[data->i_wall_index].distance *
							   cosf(g_rays[data->i_wall_index].ray_angle - data->rotation_angle);
	data->distance_to_projection_plane = ((float )data->w_width / 2) / tanf(FOV_ANGLE / 2);
	data->wall_height = (SQUARE_SIZE / data->corrected_dsitance) *
						data->distance_to_projection_plane;
	data->top_pixel = ((float )data->w_height / 2) - (data->wall_height / 2);
	data->top_pixel = data->top_pixel < 0 ? 0 : data->top_pixel;
	data->bottom_pixel = ((float )data->w_height / 2) + (data->wall_height / 2);
	data->bottom_pixel = data->bottom_pixel > (float )data->w_height
	        ? (float )data->w_height
	        : data->bottom_pixel;
}

static int get_color_index(t_struct *data) {
    return ((TEX_WIDTH * data->txt_offset_y) + data->txt_offset_x);
}

static int normalize_index(int index){
    static const int TEX_SPACE = TEX_HEIGHT * TEX_WIDTH;
    index = index <= 0 ? 0 : index;
    return index >= (TEX_SPACE) ? (TEX_SPACE - 1) : index;
}

void ft_ljodran(t_struct *data, int y)
{
	int *which_text;
	int index;

	data->txt_offset_y = (int)calculate_y_offset(data, y);
    which_text = which_texture(data);
    index = normalize_index(get_color_index(data));
	ft_draw(data, data->i_wall_index, y, data->t ? (int)which_text[index] : 0xffffff);
}

static int *which_texture(const t_struct *data) {
    if (!g_rays[data->i_wall_index].was_hit_vertical && g_rays[data->i_wall_index].is_ray_facing_down)
        return data->img_tex1;
    else if (!g_rays[data->i_wall_index].was_hit_vertical && g_rays[data->i_wall_index].is_ray_facing_up)
        return  data->img_tex2;
    else if ((g_rays[data->i_wall_index].was_hit_vertical) && g_rays[data->i_wall_index].is_ray_facing_left)
        return  data->img_tex3;
    else if ((g_rays[data->i_wall_index].was_hit_vertical) && g_rays[data->i_wall_index].is_ray_facing_right)
        return  data->img_tex4;
    return 0;
}

static float calculate_y_offset(const t_struct *data, int y)
{
    const float wall_height_by_tow = data->wall_height * 0.5F;
    const float win_height_by_tow = data->w_height * 0.5F;
    return ((float)y + (wall_height_by_tow) - (win_height_by_tow)) * ((float)TEX_WIDTH / data->wall_height);
}

void render_walls(t_struct *data)
{
	int ceilling;
	int floor;
	float y;

	data->i_wall_index = 0;
	texture_from_file(data);
	while (data->i_wall_index++ < data->w_width - 1)
	{
		ceilling = 0;
		y = data->top_pixel;
		data->txt_offset_x = calculate_x_offset(data);
		calculate_wall_projection(data);
        draw_ceilling(data, ceilling);
        draw_walls(data, y);
        floor = (int) data->bottom_pixel;
        draw_floor(data, floor);
    }
	set_up_sprite(data);
}

static void draw_walls(t_struct *data, float y) {
    while (y++ < data->bottom_pixel - 1)
        ft_ljodran(data, (int)y);
}

static void draw_floor(t_struct *data, int floor) {
    while (floor++ < data->w_height - 1)
        ft_draw(data, data->i_wall_index, floor,
                create_rgb(data->f_red, data->c_green, data->c_blue));
}

static void draw_ceilling(t_struct *data, int ceilling) {
    while (ceilling++ < (int) data->top_pixel)
        ft_draw(data, data->i_wall_index, ceilling,
                create_rgb(data->c_red, data->c_green, data->c_blue));
}

static int calculate_x_offset(const t_struct *data) {
    return (g_rays[data->i_wall_index].was_hit_vertical)
    ? ((int)g_rays[data->i_wall_index].wall_h_y % SQUARE_SIZE)
    : ((int)g_rays[data->i_wall_index].wall_h_x % SQUARE_SIZE);
}

void cast_rays(t_struct *data)
{
	int ray_id;
	float ray_angle;

	ray_id = 0;
	ray_angle = data->rotation_angle - (FOV_ANGLE / 2);
	while (ray_id < data->w_width)
	{
		cast_single_ray(ray_id, ray_angle, data);
		ray_angle += FOV_ANGLE / (float )data->w_width;
		ray_id++;
	}
}
