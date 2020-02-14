/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/14 20:23:27 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	initialize_player(t_struct *data)
{
	data->bpp = 0;
	data->endian = 0;
	data->size_line = 1;
	data->mlx_ptr = NULL;
	data->img_ptr = NULL;
	data->win_ptr = NULL;
	data->img_data = NULL;
	data->move_step = 0;
	data->updated_player_x = 0;
	data->updated_player_y = 0;
	data->x = WINDOW_WIDTH / 2;
	data->y = WINDOW_HEIGHT / 2;
	data->radius = 10;
	data->width = 6;
	data->height = 6;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->rotation_angle = PI / 2;
	data->walk_speed = 2;
	data->turn_speed = 2 * (PI / 180);
	data->is_ray_facing_down = 0;
	data->is_ray_facing_up = 0;
	data->is_ray_facing_right = 0;
	data->is_ray_facing_left = 0;
	data->dx = 0;
	data->dy = 0;
	data->x_intercept = 0;
	data->y_intercept = 0;
	data->save_horiz_wall_hit_x = 0;
	data->save_horiz_wall_hit_y = 0;
	data->save_vert_wall_hit_x = 0;
	data->save_vert_wall_hit_y = 0;
	data->vert_wall_hit_content = FALSE;
	data->horz_hit_distance = 0;
	data->vert_hit_distance = 0;
	data->corrected_dsitance = 0;
	data->top_pixel = 0;
	data->bottom_pixel = 0;
	data->distance_to_projection_plane = 0;
	data->wall_height = 0;
}

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

void	horizontal_ray_intersection(float ray_angle, t_struct *data,
int *found_horiz_wall_hit, int *horz_wall_content)
{
	float x_to_check;
	float y_to_check;

	calculate_horz_ray_intercept(data, ray_angle);
	while (data->horiz_touch_x >= 0 && data->horiz_touch_x <= WINDOW_WIDTH &&
	data->horiz_touch_y >= 0 && data->horiz_touch_y <= WINDOW_HEIGHT)
	{
		x_to_check = data->horiz_touch_x;
		y_to_check = data->horiz_touch_y + (data->is_ray_facing_up ? -1 : 0);
		if (if_wall(x_to_check, y_to_check))
		{
			data->save_horiz_wall_hit_x = data->horiz_touch_x;
			data->save_horiz_wall_hit_y = data->horiz_touch_y;
			*horz_wall_content = map[(int)floor(y_to_check / SQUARE_SIZE)]
			[(int)floor(x_to_check / SQUARE_SIZE)];
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

void	vertical_ray_intersection(float ray_angle, t_struct *data,
int *found_vert_wall_hit, int *vert_wall_content)
{
	float x_to_check;
	float y_to_check;

	calculate_vert_ray_intercept(data, ray_angle);
	while (data->vert_touch_x >= 0 && data->vert_touch_x <= WINDOW_WIDTH &&
	data->vert_touch_y >= 0 && data->vert_touch_y <= WINDOW_HEIGHT)
	{
		x_to_check = data->vert_touch_x + (data->is_ray_facing_left ? -1 : 0);
		y_to_check = data->vert_touch_y;
		if (if_wall(x_to_check, y_to_check))
		{
			data->save_vert_wall_hit_x = data->vert_touch_x;
			data->save_vert_wall_hit_y = data->vert_touch_y;
			vert_wall_content = &(map[(int)floor(y_to_check / SQUARE_SIZE)]
			[(int)floor(x_to_check / SQUARE_SIZE)]);
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
	if (data->vert_hit_distance < data->horz_hit_distance)
	{
		rays[ray_id]->distance = data->vert_hit_distance;
		rays[ray_id]->wall_h_x = data->save_vert_wall_hit_x;
		rays[ray_id]->wall_h_y = data->save_vert_wall_hit_y;
		rays[ray_id]->wall_h_content = vert_wall_content;
		rays[ray_id]->was_hit_vertical = TRUE;
	}
	else
	{
		rays[ray_id]->distance = data->horz_hit_distance;
		rays[ray_id]->wall_h_x = data->save_horiz_wall_hit_x;
		rays[ray_id]->wall_h_y = data->save_horiz_wall_hit_y;
		rays[ray_id]->wall_h_content = horz_wall_content;
		rays[ray_id]->was_hit_vertical = FALSE;
	}
	rays[ray_id]->ray_angle = data->ray_angle;
	rays[ray_id]->is_ray_facing_down = data->is_ray_facing_down;
	rays[ray_id]->is_ray_facing_up = data->is_ray_facing_up;
	rays[ray_id]->is_ray_facing_left = data->is_ray_facing_left;
	rays[ray_id]->is_ray_facing_right = data->is_ray_facing_right;
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

void	texture_from_file(t_struct *data)
{
	int		width;
	int		height;
	char	*txt_path;

	width = 0;
	height = 0;
	txt_path = "./textures/redbrick.xpm";
	data->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, txt_path,
	&width, &height);
	data->img_data_texture = (int *)mlx_get_data_addr(data->xpm_ptr,
	&data->bpp_text, &data->size_line_text, &data->endian_text);
}

void	calculate_wall_projection(t_struct *data)
{
	data->corrected_dsitance = rays[data->i_wall_index]->distance *
	cos(rays[data->i_wall_index]->ray_angle - data->rotation_angle);
	data->distance_to_projection_plane = (WINDOW_WIDTH * 0.5)
	/ tan(FOV_ANGLE / 2);
	data->wall_height = (SQUARE_SIZE / data->corrected_dsitance) *
	data->distance_to_projection_plane;
	data->top_pixel = (WINDOW_HEIGHT / 2) - (data->wall_height / 2);
	data->top_pixel = data->top_pixel < 0 ? 0 : data->top_pixel;
	data->bottom_pixel = (WINDOW_HEIGHT / 2) + (data->wall_height / 2);
	data->bottom_pixel = data->bottom_pixel > WINDOW_HEIGHT
	? WINDOW_HEIGHT
	: data->bottom_pixel;
}

void	render_walls(t_struct *data)
{
	int		cielling;
	float	y;

	data->i_wall_index = 0;
	texture_from_file(data);
	while (data->i_wall_index++ < NUM_RAYS - 1)
	{
		calculate_wall_projection(data);
		y = data->top_pixel;
		data->txt_offset_x = (rays[data->i_wall_index]->was_hit_vertical)
		? ((int)rays[data->i_wall_index]->wall_h_y % SQUARE_SIZE)
		: ((int)rays[data->i_wall_index]->wall_h_x % SQUARE_SIZE);
		while (cielling++ < data->top_pixel)
			ft_draw(data, data->i_wall_index, cielling, 0x87ceeb);
		while (y++ < data->bottom_pixel - 1)
		{
			data->txt_offset_y = (y + (int)(data->wall_height / 2)
			- (WINDOW_HEIGHT / 2)) * ((float)TEX_WIDTH
			/ (int)data->wall_height);
			ft_draw(data, data->i_wall_index, y,
			(int)data->img_data_texture[((TEX_WIDTH * data->txt_offset_y)
			+ data->txt_offset_x)
			>= (TEX_HEIGHT * TEX_WIDTH)
			? (TEX_WIDTH * TEX_HEIGHT - 1)
			: ((TEX_WIDTH * data->txt_offset_y) + data->txt_offset_x)]);
		}
		cielling = data->bottom_pixel;
		while (cielling++ < WINDOW_HEIGHT - 1)
			ft_draw(data, data->i_wall_index, cielling, 0xCDB99C);
	}
}

void	cast_rays(t_struct *data)
{
	int		ray_id;
	int		i;
	float	ray_angle;

	ray_id = 0;
	i = 0;
	ray_angle = data->rotation_angle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		cast_single_ray(ray_id, ray_angle, data);
		i++;
		ray_angle += FOV_ANGLE / NUM_RAYS;
		ray_id++;
	}
}

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (TRUE);
}

int		if_wall(float x, float y)
{
	int map_index_x;
	int map_index_y;

	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return (TRUE);
	map_index_x = floor((x / 64));
	map_index_y = floor((y / 64));
	return (map[map_index_y][map_index_x] != 0);
}

void	line(t_struct *data, int x0, int y0, int x1, int y1)
{
	size_t	i;
	int		dx;
	int		dy;
	float	x;
	float	y;
	int		steps;
	float	x_inc;
	float	y_inc;

	i = 0;
	dx = x1 - x0;
	dy = y1 - y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = x0;
	y = y0;
	while (i++ <= steps)
	{
		ft_draw(data, x, y, 0xff1100);
		x += x_inc;
		y += y_inc;
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

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		key_pressed(int keycode, t_struct *data)
{
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

int		key_released(int keycode, t_struct *data)
{
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

void	ft_draw(t_struct *data, int x, int y, int color)
{
	char *dst;

	dst = data->img_data + (y * data->size_line + x * (data->bpp / 8));
	*(u_int32_t *)dst = color;
}

int		initialize_window(t_struct *data)
{
	initialize_player(data);
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
	WINDOW_WIDTH, WINDOW_HEIGHT, "Cube3d")) == NULL)
		return (FALSE);
	if ((data->img_ptr = mlx_new_image(data->mlx_ptr,
	WINDOW_WIDTH, WINDOW_HEIGHT)) == NULL)
		return (FALSE);
	if ((data->img_data = mlx_get_data_addr(data->img_ptr,
	&data->bpp, &data->size_line, &data->endian)) == NULL)
		return (FALSE);
	render_firt_time(data);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_released, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_pressed, data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int		main(void)
{
	t_struct *data;

	data = malloc(sizeof(t_struct));
	initialize_window(data);
	free(data);
	return (0);
}
