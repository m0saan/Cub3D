/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:56:28 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/20 14:24:29 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

float	limit_angle(float angle)
{
	angle = remainderf(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int		calculate_index(float value)
{
	return (floorf((value / SQUARE_SIZE)));
}

int		get_color_index(t_struct *data)
{
	return ((TEX_WIDTH * data->txt_offset_y) + data->txt_offset_x);
}

int		normalize_index(int index)
{
	static const int tex_space = TEX_HEIGHT * TEX_WIDTH;

	index = index <= 0 ? 0 : index;
	return (index >= (tex_space) ? (tex_space - 1) : index);
}
