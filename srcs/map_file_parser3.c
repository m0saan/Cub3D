/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:15:05 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/26 16:15:10 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void get_western_texture_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	while (buff[(data->pos)] != '.' && buff[(data->pos) + 1] != '/')
		(data->pos)++;
	while (buff[(data->pos)] != '\n')
	{
		data->we[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

void get_easter_texture_path(t_struct *data, char *buff)
{
	int i;

	i = 0;
	while (buff[(data->pos)] != '.' && buff[(data->pos) + 1] != '/')
		(data->pos)++;
	while (buff[(data->pos)] != '\n')
	{
		data->ea[i] = buff[(data->pos)];
		i++;
		(data->pos)++;
	}
	data->get_to_map += 1;
}

int screw_this_norminette(t_struct *data, char *buff)
{
	if (!(fill_out_map(data, buff)))
	{
		write(1, MAP_ERR, 18);
		return (FALSE);
	}
	return (TRUE);
}
