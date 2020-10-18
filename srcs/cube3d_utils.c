/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:55:00 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/18 10:38:56 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void initialize_1(t_struct *data)
{
	data->m_height = data->n_lines * SQUARE_SIZE;
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
	data->radius = 10;
	data->width = 6;
	data->height = 6;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->rotation_angle = PI / 2;
	data->walk_speed = 75;
	data->turn_speed = 8 * (PI / 180);
	data->which_radius = 0;
	initialize_2(data);
}

void initialize_2(t_struct *data)
{
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
	data->m = 0;
	data->h = 0;
}

float limit_angle(float angle)
{
	angle = remainderf(angle, TWO_PI);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}

float distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void ft_draw(t_struct *data, int x, int y, int color)
{
	char *dst;

	dst = data->img_data + (y * data->size_line + x * (data->bpp / 8));
	*(u_int32_t *)dst = color;
}

int is_not_valid_element(t_struct *data, char *buff)
{
	return buff[data->pos] != '1' && buff[data->pos] != '0'
	&& buff[data->pos] != '2' && buff[data->pos] != 'N'
	&& buff[data->pos] != 'W' && buff[data->pos] != 'E'
	&& buff[data->pos] != 'S' && buff[data->pos] != ' ';
}

int is_player(t_struct *data, char *buff)
{
	return buff[data->pos] == 'N' || buff[data->pos] == 'W' || buff[data->pos] == 'E' || buff[data->pos] == 'S';
}

int is_sprite(char c)
{
	return c == '2';
}

int calculate_index(float value)
{
	return floor((value / SQUARE_SIZE));
}

u_int32_t create_rgb(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			*ft_mem_cpy(void *dest, const void *src, size_t n)
{
    char			*ndest;
    const char		*nsrc;
    unsigned int	i;

    i = 0;
    ndest = (char*)dest;
    nsrc = (const char*)src;
    if (!(dest || src))
        return ((char*)NULL);
    while (i < (unsigned int)n)
    {
        ndest[i] = nsrc[i];
        i++;
    }
    return ((char*)dest);
}