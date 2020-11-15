/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:21:41 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/27 17:28:25 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    setup_ui_bar(t_struct *data)
{
    data->ui.ui_xpm = mlx_xpm_file_to_image(data->mlx_ptr,
                                                "img/ui/ui.xpm", &data->ui.w, &data->ui.h);
    data->ui.img_data = (int *)mlx_get_data_addr(data->ui.ui_xpm, &data->ui.bpp, &data->ui.sl, &data->ui.end);
    data->ui.v_ratio = (float)data->ui.h / (float)data->w_height;
    data->ui.h_ratio = (float)data->ui.w / (float)300;
}

void render_ui_bar(t_struct *data){
    int x;
    int y;
    int rx;
    int ry;

    y = 0;
    ry = 0;
    setup_ui_bar(data);
    while (y < data->w_height && ry < data->ui.h)
    {
        x = 0;
        rx = 0;
        while (x < 300 && rx < data->ui.w)
        {
            int index = (ry * data->ui.w) + rx;
            int color = data->ui.img_data[index];
            ft_draw(data, x, y, color);
            rx = ++x * data->ui.h_ratio;
        }
        ry = ++y * data->ui.v_ratio;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void    setup_splash_screen(t_struct *data, char *splash_screen)
{
    data->splsh.spl_xpm = mlx_xpm_file_to_image(data->mlx_ptr, splash_screen, &data->splsh.w, &data->splsh.h);
    data->splsh.img_data = (int *)mlx_get_data_addr(data->splsh.spl_xpm, &data->splsh.bpp, &data->splsh.sl, &data->splsh.end);
    data->splsh.vratio = (float)data->splsh.h / (float)data->w_height;
    data->splsh.hratio = (float)data->splsh.w / (float)data->w_width;
}

void render_splash_screen(t_struct *data, char *splash_screen)
{
    int x;
    int y;
    int rx;
    int ry;

    y = 0;
    ry = 0;
    setup_splash_screen(data, splash_screen);
    while (y < data->w_height && ry < data->splsh.h)
    {
        x = 0;
        rx = 0;
        while (x < data->w_width && rx < data->splsh.w)
        {
            int index = (ry * data->splsh.w) + rx;
            int color = data->splsh.img_data[index];
            ft_draw(data, x, y, color);
            rx = ++x * data->splsh.hratio;
        }
        ry = ++y * data->splsh.vratio;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}


int		update(t_struct *data)
{
    if (!data->start && !g_screenshot)
        render_splash_screen(data, "img/start/start.xpm");
    else {
        cast_rays(data);
        render_walls(data);
        move_player(data);
        if (g_screenshot) {
            screen(data);
            destruct(data);
            ft_close(data);
        }
        if (data->reset)
            init_player(data);
        if (data->h)
            help_text(data);
        render_ui_bar(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    }
    return (FALSE);
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
    if (!initialize_window(data))
		return (TRUE);
	free(data);
    return (FALSE);
}
