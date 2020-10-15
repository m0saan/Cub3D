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

#include "../include/cube3d.h"

void horizontal_ray_intersection(float ray_angle, t_struct *data,
                                 int *found_horiz_wall_hit)
{
    calculate_horz_ray_intercept(data, ray_angle);
    while (data->horiz_touch_x >= 0 && data->horiz_touch_y >= 0)
    {
        data->x_horz_to_check = data->horiz_touch_x;
        data->y_horz_to_check = data->horiz_touch_y + (data->is_ray_facing_up ? -1 : 0);
        if (if_wall(data->x_horz_to_check, data->y_horz_to_check, data))
        {
            data->save_horiz_wall_hit_x = data->horiz_touch_x;
            data->save_horiz_wall_hit_y = data->horiz_touch_y;
            *found_horiz_wall_hit = TRUE;
            break;
        }
        else
        {
            data->horiz_touch_x += data->dx;
            data->horiz_touch_y += data->dy;
        }
    }
}

void vertical_ray_intersection(float ray_angle, t_struct *data, int *found_vert_wall_hit)
{
    calculate_vert_ray_intercept(data, ray_angle);
    while (data->vert_touch_x >= 0 && data->vert_touch_y >= 0)
    {
        data->x_vert_to_check = data->vert_touch_x + (data->is_ray_facing_left ? -1 : 0);
        data->y_vert_to_check = data->vert_touch_y;
        if (if_wall(data->x_vert_to_check, data->y_vert_to_check, data))
        {
            data->save_vert_wall_hit_x = data->vert_touch_x;
            data->save_vert_wall_hit_y = data->vert_touch_y;
            *found_vert_wall_hit = TRUE;
            break;
        }
        else
        {
            data->vert_touch_x += data->dx;
            data->vert_touch_y += data->dy;
        }
    }
}

static int valid_indeces(t_struct *data, int x, int y)
{
    int i;
    int j;

    i = 0;
    j = 0;

    if (y > data->n_lines)
        return FALSE;
    while (i < data->n_lines)
    {
        if (x > g_lines_length[i])
            return FALSE;
        i++;
    }
    return TRUE;
}

int if_wall(float x, float y, t_struct *data)
{
    int map_index_x;
    int map_index_y;

    map_index_x = floor((x / SQUARE_SIZE));
    map_index_y = floor((y / SQUARE_SIZE));

    if (!valid_indeces(data, map_index_x, map_index_y))
        return TRUE;
    if ((y < 0 || y > data->m_height) || (map_index_y > data->n_lines))
        return (TRUE);

    return (data->map[map_index_y][map_index_x] == ' ' || data->map[map_index_y][map_index_x] == '1');
}

int initialize_window(t_struct *data)
{
    initialize_1(data);
    if ((data->mlx_ptr = mlx_init()) == NULL)
        return (TRUE);
    if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
                                        data->w_width, data->w_height, "Cube3d")) == NULL)
        return (TRUE);
    if ((data->img_ptr = mlx_new_image(data->mlx_ptr,
                                       data->w_width, data->w_height)) == NULL)
        return (TRUE);
    if ((data->img_data = mlx_get_data_addr(data->img_ptr,
                                            &data->bpp, &data->size_line, &data->endian)) == NULL)
        return (TRUE);
    initialize_sprite(data);
    mlx_hook(data->win_ptr, 3, 0, key_released, data);
    mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
    mlx_loop_hook(data->mlx_ptr, update, data);
    mlx_loop(data->mlx_ptr);
    return (FALSE);
}

int main(int ac, char *av[])
{
    t_struct *data;

    if (ac != 2)
    {
        write(1, "No map included!\n", 17);
        return (1);
    }
    data = malloc(sizeof(t_struct));
    if (parse(data, av))
        return (1);
    g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
    if (initialize_window(data))
        return (TRUE);
    free(data);
    return (FALSE);
}