/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:29:35 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/20 14:06:56 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	change_song(t_struct *data, int song_num)
{
	if (data->mu > 0)
		system("killall afplay 2&>/dev/null >/dev/null");
	if (song_num == 1)
		system("afplay songs/song1.mp3&");
	else if (song_num == 2)
		system("afplay songs/song2.mp3&");
	else if (song_num == 3)
		system("afplay songs/song3.mp3&");
	else if (song_num == 4)
		system("afplay songs/song4.mp3&");
}

void	setup_ui_bar(t_struct *data)
{
    if ((data->ui.ui_xpm = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/ui/ui.xpm", &data->ui.w, &data->ui.h)) == NULL)
        error("Error detected");
	if ((data->ui.img_data = (int *)mlx_get_data_addr(data->ui.ui_xpm,
			&data->ui.bpp, &data->ui.sl, &data->ui.end)) == NULL)
        error("Error detected");
	data->ui.v_ratio = (float)data->ui.h / (float)data->w_height;
	data->ui.h_ratio = (float)data->ui.w / (float)data->ui_bar_size;
}

void	render_ui_bar(t_struct *data)
{
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
		while (x < data->ui_bar_size && rx < data->ui.w)
		{
			ft_draw(data, x, y, data->ui.img_data[(ry * data->ui.w) + rx]);
			rx = ++x * data->ui.h_ratio;
		}
		ry = ++y * data->ui.v_ratio;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	setup_splash_screen(t_struct *data, char *splash_screen)
{
	if ((data->splsh.spl_xpm = mlx_xpm_file_to_image(data->mlx_ptr, splash_screen,
			&data->splsh.w, &data->splsh.h)) == NULL)
        error("Error detected");
	if ((data->splsh.img_data = (int *)mlx_get_data_addr(data->splsh.spl_xpm,
			&data->splsh.bpp, &data->splsh.sl, &data->splsh.end)) == NULL)
        error("Error detected");
	data->splsh.vratio = (float)data->splsh.h / (float)data->w_height;
	data->splsh.hratio = (float)data->splsh.w / (float)data->w_width;
}

void	render_splash_screen(t_struct *data, char *splash_screen)
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
			ft_draw(data, x, y, data->splsh.img_data[(ry * data->splsh.w)
					+ rx]);
			rx = ++x * data->splsh.hratio;
		}
		ry = ++y * data->splsh.vratio;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
