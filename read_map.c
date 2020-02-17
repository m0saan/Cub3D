/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:09:17 by moboustt          #+#    #+#             */
/*   Updated: 2020/01/14 15:51:03 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}
void read_map(t_read *data)
{
	int pos;

	pos = 0;
	data->fd = open("map.cub", O_RDONLY);
	while (get_next_line(data->fd, &data->line))
	{
		if (data->line[pos] == 'R')
		{
			pos++;
			data->height = ft_atoi(&data->line[pos++]);
			pos += skip_number(&data->line[pos]);
			data->width = ft_atoi(&data->line[pos]);
			pos = 0;
		}
		if (data->line[pos] == 'F')
		{
			pos++;
			data->f_red = ft_atoi(&data->line[pos++]);
			pos += skip_number(&data->line[pos]);
			data->f_green = ft_atoi(&data->line[pos + 1]);
			pos += skip_number(&data->line[pos]);
			data->f_blue = ft_atoi(&data->line[pos + 1]);
			pos = 0;
		}
		if (data->line[pos] == 'C')
		{
			pos += 2;
			data->c_red = ft_atoi(&data->line[pos]);
			pos += skip_number(&data->line[pos]);
			data->c_green = ft_atoi(&data->line[pos + 1]);
			pos += skip_number(&data->line[pos]);
			data->c_blue = ft_atoi(&data->line[pos + 1]);
		}
		pos = 0;
	}
}
void	read_map(t_read *data)
{

}
int main()
{
	t_read *data;
	read_map(data);
	printf("height = %d\n", data->height);
	printf("width = %d\n", data->height);
	printf("floor red = %d\n", data->f_red);
	printf("floor red = %d\n", data->f_green);
	printf("floor red = %d\n", data->f_blue);
	return 0;
}
