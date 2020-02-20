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

int map[NUM_ROWS][NUM_COLS] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 'N', 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
void	sprite(t_struct *data)
{

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
			if ( map[(int)floor(y_to_check / SQUARE_SIZE)][(int)floor(x_to_check / SQUARE_SIZE)] == 2)
				data->was_touching_sprite = 1;
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

int		initialize_window(t_struct *data)
{
	initialize_1(data);
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
	mlx_hook(data->win_ptr, 3, 0, key_released, data);
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int		main(int argc, char *argv[])
{
	t_struct *data;

	data = malloc(sizeof(t_struct));
	initialize_window(data);
	free(data);
	return (0);
}

#include "cube3d.h"

void draw_line(t_struct *data)
{
	float j;
	float i;
	float radius;

	i = data->x;
	j = data->y;
	radius = 40;
	while (radius > 0)
	{
		j = data->y;
		while (j++ < data->y + 1)
			ft_draw(data, i + cos(data->rotation_angle) * radius *
			MINI, j + sin(data->rotation_angle) * radius * MINI, 0x4287f5);
		radius -= 1;
	}
}

void 	texture(t_struct *data)
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

void circle(t_struct *data)
{
	float two_pi;
	float i;
	float get_radius;

	two_pi = 2 * PI;
	i = 0;
	get_radius = data->which_radius ? SQUARE_SIZE : data->radius;
	while (get_radius > 0)
	{
		i = 0;
		while (i <= two_pi)
		{
			ft_draw(data, MINI * ((cos(i) * get_radius) + data->x), MINI * ((sin(i) * get_radius) + data->y), 0xfcba03);
			i += 0.1;
		}
		get_radius -= 0.1;
	}
}

void fill_square(int square_x, int square_y, int tile_size, int tile_color, t_struct *data)
{
	int i;
	int j;

	i = square_x;
	j = 0;
	while (i++ < tile_size + square_x)
	{
		j = square_y;
		while (j++ < tile_size + square_y)
			ft_draw(data, i * MINI, j * MINI, tile_color);
	}
}

int render_map(t_struct *data)
{
	int i;
	int j;
	int square_x;
	int square_y;
	int square_color;

	i = 0;
	j = 0;
	square_x = 0;
	square_y = 0;
	square_color = 0;

	while (i < NUM_ROWS)
	{
		while (j < NUM_COLS)
		{
			square_x = j * SQUARE_SIZE;
			square_y = i * SQUARE_SIZE;
			if (map[i][j] == 2)
				square_color = 0xa29bfe;
			else
				square_color = map[i][j] != 0 ? 0x2ecc71 : 0xecf0f1;
			fill_square(square_x - 1, square_y - 1, SQUARE_SIZE, square_color, data);
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

void render_all_rays(t_struct *data)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		line(data, data->x * MINI, data->y * MINI, rays[i]->wall_h_x * MINI, rays[i]->wall_h_y * MINI);
		i++;
	}
}

void mini_map(t_struct *data)
{
	render_map(data);
	circle(data);
	cast_rays(data);
	move_player(data);
}
