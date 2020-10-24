/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:54:35 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 10:11:10 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_pressed(int keycode, t_struct *data)
{
	if (keycode == 17)
		data->t = data->t == 0 ? 1 : 0;
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

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		destruct(t_struct *data)
{
	int i;

	i = 0;
	free(data->no);
	free(data->so);
	free(data->ea);
	free(data->we);
	free(data->sprite);
	while (i < data->n_lines)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	free(g_rays);
	exit(1);
}

int		is_not_valid_xpm(t_struct *data)
{
	return (!data->xpm_ptr1 || !data->xpm_ptr2
		|| !data->xpm_ptr3 || !data->xpm_ptr4 || !data->sprite_xpm);
}
