/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:32:00 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/01 16:56:35 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	help_text(t_struct *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 20,
			0X000000, "Press W A S D or the arrow keys to move.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 40, 0X000000, "Press SHIFT to sprint.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 60,
			0X000000, "Press R to reset the player.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 80,
			0X000000, "Press T to show or hide textures.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 100,
			0X000000, "Press H to show or hide this help.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->m ? 400 : 10, 120,
			0X000000, "Press ESC to quit.");
}
