/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 00:24:37 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/18 10:45:45 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rgb	*g_rgb;

int		screen(t_struct *data)
{
	int				x;
	const char		*file_name = "screenshot.bmp";
	const int		len = 54;
	unsigned char	header[len];

	ft_memset(header, 0, len);
	screen_init(data, header);
	data->bitmap.buf = malloc((data->bitmap.image_size));
	x = 0;
	data->bitmap.row = data->w_height - 1;
	while (data->bitmap.row-- >= 0)
	{
		data->bitmap.col = 0;
		while (data->bitmap.col++ < data->w_width - 1)
			screen_data(data, x);
		x++;
	}
	data->bitmap.fd = open(file_name, O_WRONLY | O_CREAT);
	write(data->bitmap.fd, header, len);
	write(data->bitmap.fd, data->bitmap.buf, data->bitmap.image_size);
	close(data->bitmap.fd);
	free(data->bitmap.buf);
	return (0);
}

void	screen_data(t_struct *data, int x)
{
	int index;

	index = data->bitmap.row * data->w_width + data->bitmap.col;
	index = index < 0 ? index * (-1) : index;
	g_rgb = color_converter((uint32_t)data->img_data_bmp[index]);
	data->bitmap.buf[x * data->bitmap.width_in_pxl
		+ data->bitmap.col * 3 + 0] = g_rgb->b;
	data->bitmap.buf[x * data->bitmap.width_in_pxl
		+ data->bitmap.col * 3 + 1] = g_rgb->g;
	data->bitmap.buf[x * data->bitmap.width_in_pxl
		+ data->bitmap.col * 3 + 2] = g_rgb->r;
	free(g_rgb);
}

void	screen_init(t_struct *data, unsigned char *header)
{
	data->bitmap.bit_per_pxl = 24;
	data->bitmap.width_in_pxl = ((data->w_width *
				data->bitmap.bit_per_pxl + 31) / 32) * 4;
	data->bitmap.image_size = data->bitmap.width_in_pxl * data->w_height;
	data->bitmap.info_header_size = 40;
	data->bitmap.bf_off_bits = 54;
	data->bitmap.file_size = 54 + data->bitmap.image_size;
	data->bitmap.biplanes = 1;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &(data->bitmap.file_size), 4);
	ft_memcpy(header + 10, &(data->bitmap.bf_off_bits), 4);
	ft_memcpy(header + 14, &(data->bitmap.info_header_size), 4);
	ft_memcpy(header + 18, &(data->w_width), 4);
	ft_memcpy(header + 22, &(data->w_height), 4);
	ft_memcpy(header + 26, &(data->bitmap.biplanes), 2);
	ft_memcpy(header + 28, &(data->bitmap.bit_per_pxl), 2);
}
