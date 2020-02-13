#include "cube3d.h"

void texture_from_file(t_struct *data)
{
	int width;
	int height;
	char *txt_path;
	int *texture_img_data;

	width = 0;
	height = 0;
	txt_path = "./textures/stone.xpm";
	data->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, txt_path, &width, &height);
	data->img_data_texture = (int *)mlx_get_data_addr(data->xpm_ptr, &data->bpp_text, &data->size_line_text, &data->endian_text);
}
void texture(t_struct *data)
{
	int x;
	int y;
	int pos = 0;

	x = 0;
	y = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			pos = (TEX_WIDTH * y) + x;
			buff[pos] = (x % 8 && y % 8) ? 0x3c40c6 : 0x1e272e;
			y++;
		}
		x++;
	}
}
void render_walls(t_struct *data)
{
	int i;
	int pos = 0;
	int txt_offset_x = 0;
	int txt_offset_y = 0;
	int cielling = 0;
	float y = 0;
	float corrected_dsitance;
	float top_pixel;
	float bottom_pixel;
	float distance_to_projection_plane;
	float wall_height;

	i = 0;
	top_pixel = 0;
	bottom_pixel = 0;
	distance_to_projection_plane = 0;
	wall_height = 0;
	texture_from_file(data);
	while (i < NUM_RAYS)
	{
		corrected_dsitance = rays[i]->distance * cos(rays[i]->ray_angle - data->rotation_angle);
		distance_to_projection_plane = (WINDOW_WIDTH * 0.5) / tan(FOV_ANGLE / 2);
		wall_height = (SQUARE_SIZE / corrected_dsitance) * distance_to_projection_plane;
		top_pixel = (WINDOW_HEIGHT / 2) - (wall_height / 2);
		top_pixel = top_pixel < 0 ? 0 : top_pixel;
		bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_height / 2);
		bottom_pixel = bottom_pixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : bottom_pixel;
		y = top_pixel;
		txt_offset_x = (rays[i]->was_hit_vertical) ? ((int)rays[i]->wall_h_y % SQUARE_SIZE) : ((int)rays[i]->wall_h_x % SQUARE_SIZE);
		while (cielling++ < top_pixel)
			ft_draw(data, i, cielling, 0x87ceeb);
		while (y < bottom_pixel)
		{
			txt_offset_y = (y + (int)(wall_height / 2) - (WINDOW_HEIGHT / 2)) * ((float)TEX_WIDTH / (int)wall_height);
			pos = (TEX_WIDTH * txt_offset_y) + txt_offset_x;
			pos = (pos > TEX_HEIGHT * TEX_WIDTH) ? (TEX_WIDTH * TEX_HEIGHT) : pos;
			ft_draw(data, i, y, data->img_data_texture[pos]);
			y++;
		}
		cielling = bottom_pixel;
		while (cielling < WINDOW_HEIGHT)
		{
			ft_draw(data, i, cielling, 0xCDB99C);
			cielling++;
		}
		i++;
	}
}