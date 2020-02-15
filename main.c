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
