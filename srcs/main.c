/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/19 23:59:59 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_player(t_struct *data)
{
	static int count;

	count = 0;
	data->x = (data->j + 0.5) * SQUARE_SIZE;
	data->y = (data->i + 0.5) * SQUARE_SIZE;
	count++;
	set_up_player(data, count);
}

void	set_up_player(t_struct *data, int player)
{
	if (player != 1)
	{
		write(1, "Player error!\n", 14);
		exit(0);
	}
	data->orientation = data->map[data->i][data->j];
	if (data->orientation == 'N')
		data->rotation_angle = RAD(270);
	else if (data->orientation == 'W')
		data->rotation_angle = RAD(180);
	else if (data->orientation == 'S')
		data->rotation_angle = RAD(90);
	else if (data->orientation == 'E')
		data->rotation_angle = RAD(0);
}

int		set_up_window(t_struct *data)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
					data->w_width, data->w_height, "Cube3d")) == NULL)
		return (FALSE);
	if ((data->img_ptr = mlx_new_image(data->mlx_ptr,
					data->w_width, data->w_height)) == NULL)
		return (FALSE);
	if ((data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
					&data->size_line, &data->endian)) == NULL)
		return (FALSE);
	data->img_data_bmp = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_line, &data->endian);
	return (TRUE);
}

int		initialize_window(t_struct *data)
{
	set_up_data(data);
	if (!(set_up_window(data)))
		return (FALSE);
	update(data);
	mlx_hook(data->win_ptr, 3, 0, key_released, data);
	mlx_hook(data->win_ptr, 2, 0, key_pressed, data);
	mlx_hook(data->win_ptr, 17, 0L, destruct, data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int		are_valid_args(int ac, char **av)
{
	if (ac < 2)
		error("No map included!\n");
	else if (ac == 2 && strstr(av[1], ".cub"))
		return (TRUE);
	else if (ac == 3 && !strcmp(av[2], "--save"))
	{
		g_screenshot = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int		main(int ac, char *av[])
{
	t_struct *data;

	if (!are_valid_args(ac, av))
		return (TRUE);
	data = malloc(sizeof(t_struct));
	if (!parse(data, av))
		return (1);
	g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
	if (!initialize_window(data))
		return (TRUE);
	free(data);
	return (FALSE);
}
