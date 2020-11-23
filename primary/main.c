/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/21 17:43:32 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		update(t_struct *data)
{
	cast_rays(data);
	render_walls(data);
	move_player(data);
	if (g_screenshot)
	{
		screen(data);
		destruct(data);
		ft_close(data);
	}
	if (data->reset)
		init_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 0, 0);
	return (FALSE);
}

int		initialize_window(t_struct *data)
{
	set_up_data(data);
	if (!(set_up_window(data)))
		return (FALSE);
	texture_from_file(data);
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
	else if (ac == 2 && ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		return (TRUE);
	else if (ac == 3 && ft_strlen(av[2]) == 6
			&& !ft_strncmp(av[2], "--save", ft_strlen(av[2])))
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
		error("args are not valid\n");
	data = malloc(sizeof(t_struct));
	if (!parse(data, av))
		return (1);
	g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
	if (!initialize_window(data))
		return (TRUE);
	free(data);
	return (FALSE);
}
