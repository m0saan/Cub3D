/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:35 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/27 17:40:32 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int key_pressed(int keycode, t_struct *data)
{
    if (keycode >= 18 && keycode <= 21)
    {
        data->mu = 2;
        change_song(data, keycode - 17);
    }
    if (keycode == 36)
        data->start = 1;
    if (keycode == 15)
        data->reset = data->reset == 0 ? 1 : 0;
    if (keycode == 257)
        data->shift = data->shift == 0 ? 1 : 0;
    if (keycode == 46)
        data->m = data->m == 0 ? 1 : 0;
    if (keycode == 4)
        data->h = data->h == 0 ? 1 : 0;
    if (keycode == 17)
        data->t = data->t == 0 ? 1 : 0;
    if (keycode == 53)
    {
        system("killall afplay 2&>/dev/null >/dev/null");
        destruct(data);
        ft_close(data);
    }
    if (keycode == 0)
    {
        data->left = (M_PI * 0.5F) * (-1);
        data->walk_direction = 1;
    }
    if (keycode == 2)
    {
        data->left = M_PI * 0.5F;
        data->walk_direction = 1;
    }
    if (keycode == 13)
        data->walk_direction = 1;
    if (keycode == 1)
        data->walk_direction = -1;
    if (keycode == 124)
        data->turn_direction = 1;
    if (keycode == 123)
        data->turn_direction = -1;
    return (TRUE);
}

int key_released(int keycode, t_struct *data)
{
    if (keycode == 15)
        data->reset = data->reset == 1 ? 0 : 1;
    if (keycode == 257)
        data->shift = data->shift == 1 ? 0 : 1;
    if (keycode == 13)
        data->walk_direction = 0;
    if (keycode == 1)
        data->walk_direction = 0;
    if (keycode == 124)
        data->turn_direction = 0;
    if (keycode == 123)
        data->turn_direction = 0;
    if (keycode == 0)
    {
        data->left = 0;
        data->walk_direction = 0;
    }
    if (keycode == 2)
    {
        data->left = 0;
        data->walk_direction = 0;
    }
    return (TRUE);
}

int ft_close(void *param)
{
    (void)param;
    exit(0);
}

int destruct(t_struct *data)
{
    int i;

    i = 0;
    system("killall afplay 2&>/dev/null >/dev/null");
    free(data->sprite);
    while (i < data->n_lines - 1)
    {
        free(data->map[i]);
        i++;
    }
    free(data);
    free(g_rays);
    ft_close(0);
    return 0;
}

int is_not_valid_xpm(t_struct *data)
{
    return (!data->xpm_ptr1 || !data->xpm_ptr2 || !data->xpm_ptr3 || !data->xpm_ptr4 || !data->sprite_xpm);
}
