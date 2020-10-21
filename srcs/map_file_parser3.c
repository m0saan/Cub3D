/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:15:05 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/21 11:46:54 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int is_valid_texture(t_struct *data, const char *buff) {
    int flag;

    flag = 0;
    while (buff[data->pos] != '.' && buff[data->pos + 1] != '/' && ++flag) {
        if (buff[data->pos] == '\n') error("Invalid texture alignment\n");
        (data->pos)++;
    }
    return flag;
}

void	get_western_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
    if (is_valid_texture(data, buff) != 3)
	    error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n')
	{
		data->we[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

void	get_easter_texture_path(t_struct *data, const char *buff)
{
	int i;

	i = 0;
    if (is_valid_texture(data, buff) != 3)
        error("Invalid texture path!\n");
	while (buff[(data->pos)] != '\n')
	{
		data->ea[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

int		screw_this_norminette(t_struct *data, char *buff)
{
	data->count_spt = 0;
	fill_out_map(data, buff);
	return (TRUE);
}
