/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:25:21 by moboustt          #+#    #+#             */
/*   Updated: 2020/11/28 10:38:07 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

int	destruct(t_struct *data)
{
	int i;

	i = 0;
	system("killall afplay 2&>/dev/null >/dev/null");
	free(data->sprite);
	while (i < data->n_lines - 1)
	{
		free(data->map[i]);
		i++;
	}
	free(data);
	free(g_rays);
	ft_close(0);
	return (0);
}
