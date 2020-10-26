/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:32:00 by tglandai          #+#    #+#             */
/*   Updated: 2020/10/26 14:25:23 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	help_text(t_struct *data)
{
    mlx_string_put(data->mlx_ptr, data->win_ptr,0, 20,0X000000, "Press W A S D or the arrow keys to move.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 40, 0X000000, "Press SHIFT to sprint.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 60,0X000000, "Press R to reset the player.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 80,0X000000, "Press T to show or hide textures.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 100,0X000000, "Press H to show or hide this help.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 120, 0X000000, "Press ESC to quit.");
}
