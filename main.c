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
void	render_sprite(t_struct *data)
{

}
void	horizontal_ray_intersection(float ray_angle, t_struct *data,
int *found_horiz_wall_hit, int *horz_wall_content)
{
	calculate_horz_ray_intercept(data, ray_angle);
	while (data->horiz_touch_x >= 0 && data->horiz_touch_x <= data->m_width &&
	data->horiz_touch_y >= 0 && data->horiz_touch_y <= data->m_height)
	{
		data->x_horz_to_check = data->horiz_touch_x;
		data->y_horz_to_check = data->horiz_touch_y + (data->is_ray_facing_up ? -1 : 0);
		if (if_wall(data->x_horz_to_check, data->y_horz_to_check, data))
		{
			data->save_horiz_wall_hit_x = data->horiz_touch_x;
			data->save_horiz_wall_hit_y = data->horiz_touch_y;
			*horz_wall_content = data->map[(int)floor(data->y_horz_to_check / SQUARE_SIZE)]
			[(int)floor(data->x_horz_to_check / SQUARE_SIZE)];
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
	calculate_vert_ray_intercept(data, ray_angle);
	while (data->vert_touch_x >= 0 && data->vert_touch_x <= data->m_width &&
	data->vert_touch_y >= 0 && data->vert_touch_y <= data->m_height)
	{
		data->x_vert_to_check = data->vert_touch_x + (data->is_ray_facing_left ? -1 : 0);
		data->y_vert_to_check = data->vert_touch_y;
		if (if_wall(data->x_vert_to_check, data->y_vert_to_check, data))
		{
			data->save_vert_wall_hit_x = data->vert_touch_x;
			data->save_vert_wall_hit_y = data->vert_touch_y;
			vert_wall_content = &(data->map[(int)floor(data->y_vert_to_check / SQUARE_SIZE)]
			[(int)floor(data->x_vert_to_check / SQUARE_SIZE)]);
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

int		if_wall(float x, float y, t_struct *data)
{
	int map_index_x;
	int map_index_y;

	if ((x < 0 || x > data->m_width) || (y < 0 || y > data->m_height))
		return (TRUE);
	map_index_x = floor((x / SQUARE_SIZE));
	map_index_y = floor((y / SQUARE_SIZE));
	return (data->map[map_index_y][map_index_x] != 0);
}

int		initialize_window(t_struct *data)
{
	initialize_1(data);
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
	data->w_width, data->w_height, "Cube3d")) == NULL)
		return (FALSE);
	if ((data->img_ptr = mlx_new_image(data->mlx_ptr,
	data->w_width, data->w_height)) == NULL)
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

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		write(1, "No map included!\n", 17);
		return 1;
	}
	t_struct *data;

	data = malloc(sizeof(t_struct));
	if (parse(data, av))
		return 1;
	initialize_window(data);
	free(data);
	return (0);
}

void render_all_rays(t_struct *data)
{
	int i;

	i = 0;
	while (i < data->w_width)
	{
		line(data, data->x * MINI, data->y * MINI, rays[i]->wall_h_x * MINI, rays[i]->wall_h_y * MINI);
		i++;
	}
}

unsigned long creatergb(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}