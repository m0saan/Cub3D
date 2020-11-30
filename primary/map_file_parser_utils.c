/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:11:07 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/28 10:38:07 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		is_valid_texture(t_struct *data, const char *buff)
{
	if (buff[data->pos] != ' ')
		return (FALSE);
	while (buff[data->pos] != '.' && buff[data->pos + 1] != '/')
	{
		if (ft_isalpha(buff[data->pos]))
			return (TRUE);
		if (buff[data->pos] != ' ')
			error("\e[0;31m Invalid separator\n");
		if (buff[data->pos] == '\n')
			error("\e[0;31m Invalid texture alignment\n");
		(data->pos)++;
	}
	return (buff[data->pos] == '.' && buff[data->pos + 1] == '/');
}

int		is_negative(int v)
{
	return (v < 0);
}

int		screw_this_norminette(t_struct *data, char *buff)
{
	data->count_spt = 0;
	data->is_multi_player = FALSE;
	fill_out_map(data, buff);
	return (TRUE);
}

void	check_after_given_infos(t_struct *data, const char *buff)
{
	while (buff[data->pos] != '\n')
	{
		if (buff[data->pos] != ' ')
			error("\e[0;31m Invalid elements\n");
		data->pos++;
	}
}

void	not_valid_element(const t_struct *data, const char *buff)
{
	if (buff[data->pos] == '\n' && buff[data->pos] == ' ')
		error("\e[0;31m Error detected\n");
	if (buff[data->pos] != '\n' &&
	buff[data->pos] != ' ' && buff[data->pos] != '0' && buff[data->pos] != '1')
		error("\e[0;31m Error detected\n");
}
