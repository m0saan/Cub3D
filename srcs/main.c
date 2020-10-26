/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/26 13:50:46 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_splash_screen(t_struct *data)
{
    data->splsh.spl_xpm = mlx_xpm_file_to_image(data->mlx_ptr,
                                                "img/start/start.xpm", &data->splsh.w, &data->splsh.h);
    data->splsh.splsh_data = (int *)mlx_get_data_addr(data->splsh.spl_xpm, &data->bpp, &data->size_line, &data->endian);
    data->splsh.vratio = (float)data->splsh.h / data->w_height;
    data->splsh.hratio = (float)data->splsh.w / data->w_width;
}

void update_rendering_hud(t_struct *data)
{
    int x;
    int y;
    int rx;
    int ry;

    y = 0;
    ry = 0;
    while (y < data->w_height && ry < data->splsh.h)
    {
        x = 0;
        rx = 0;
        while (x < data->w_width && rx < data->splsh.w)
        {
            int index = (ry * data->splsh.w) + rx;
            ft_draw(data, x, y, data->splsh.splsh_data[index]);
            rx = ++x * (int)data->splsh.hratio;
        }
        ry = ++y * (int)data->splsh.vratio;
    }
}

void start(t_struct *data){
    update_rendering_hud(data);
}

int		update(t_struct *data)
{
    if (!data->start && !g_screenshot)
        start(data);
    else {
        cast_rays(data);
        render_walls(data);
        move_player(data);
        if (g_screenshot) {
            screen(data);
            ft_close(data);
        }
        if (data->reset)
            init_player(data);
        //if (data->m)
        //    mini_map(data);
    }
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
        if (data->h)
            help_text(data);
    //mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, xpm, 0, 0);
    for (int i = 0; i < 300; ++i) {
        for (int j = 0; j < data->w_height; ++j)
            ft_draw(data, i, j, UI_B);
    }
	return (FALSE);
}

int		initialize_window(t_struct *data)
{
	set_up_data(data);
	if (!(set_up_window(data)))
		return (FALSE);
    update(data);
    init_splash_screen(data);
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
	else if (ac == 3 && !ft_strncmp(av[2], "--save", ft_strlen(av[2])))
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
		error("something went wrong\n");
	data = malloc(sizeof(t_struct));
	if (!parse(data, av))
		return (1);
	g_rays = (t_ray *)malloc(sizeof(t_ray) * data->w_width);
    system("afplay songs/song1.mp3&");
    printf("width == %d\n", data->w_width);
    printf("height == %d\n", data->w_height);
    if (!initialize_window(data))
		return (TRUE);
	free(data);
    return (FALSE);
}
