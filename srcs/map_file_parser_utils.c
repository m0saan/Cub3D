/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:15:05 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 14:24:27 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		is_valid_texture(t_struct *data, const char *buff)
{
	int flag;

	flag = 0;
	while (buff[data->pos] != '.' && buff[data->pos + 1] != '/' && ++flag)
	{
		if (buff[data->pos] == '\n')
			error("Invalid texture alignment\n");
		(data->pos)++;
	}
	return (flag);
}

int		is_negative(int v)
{
	return (v < 0);
}

int		screw_this_norminette(t_struct *data, char *buff)
{
	data->count_spt = 0;
	fill_out_map(data, buff);
	return (TRUE);
}
