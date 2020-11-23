/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:54:58 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/23 12:49:31 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
    system("killall afplay 2&>/dev/null >/dev/null");
	exit(EXIT_FAILURE);
}

int		is_valid_color(const t_struct *data, int id)
{
	return (data->sprite_tex_data[id] != data->sprite_tex_data[0]);
}
