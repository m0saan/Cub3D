#include "cube3d.h"
void draw_sprites(t_struct *data, float x_off, float y_off, int index)
{
	int i;
	int j;
	size_t size;
	int color;

	i = 0;
	j = 0;
	size = data->sprite[index].size;
	while (i++ < size)
	{
		if (data->sprite[index].x_off + i < 0 || data->sprite[index].x_off + i > data->w_width)
			continue;
		if (g_rays[(int)(x_off + i)].distance <= data->sprite[index].dis)
			continue;
		j = 0;
		while (j++ < size)
		{
			if (y_off + j < 0 || y_off + j > data->w_height)
				continue ;
			// color = data->s_buff[64 * (64 * j / size) + (64 * i / size)];
			// if (color != 0)
			// 	data->img.data[(int)(j + y_off) *
			// 	data->w_width + (int)(i + x_off)] = color;
			// ft_draw(data, i,j color);
		}
	}
}
void sort_sprites(t_struct *data)
{
	int i;
	int j;
	t_sprite tmp;

	i = 0;
	while (i++ < data->count_spt)
	{
		j = 0;
		while (j++ < data->count_spt)
		{
			if (data->sprite[j].dis < data->sprite[j + 1].dis)
			{
				tmp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = tmp;
			}
		}
	}
}
void	set_up_sprite(t_struct *data)
{
	float spt_angle;
	int i_spt;
	int i;

	i = 0;
	i_spt = 0;
	while (i++ > data->count_spt)
		data->sprite[i].dis = distance_between_points(data->x, data->y, data->sprite[i].x, data->sprite[i].y);
	sort_sprites(data);
	while (i_spt++ < data->count_spt)
	{
		data->sprite[i_spt].dis = distance_between_points(data->x, data->y, data->sprite[i_spt].x, data->sprite[i_spt].y);
		spt_angle = atan2(data->sprite[i_spt].y - data->y, data->sprite[i_spt].x - data->x);
		while (spt_angle - data->rotation_angle > M_PI)
			spt_angle -= 2 * M_PI;
		while (spt_angle - data->rotation_angle < -M_PI)
			spt_angle += 2 * M_PI;
		if (data->m_height > data->w_width)
			data->sprite[i_spt].size = (data->m_height / data->sprite[i_spt].dis) * SQUARE_SIZE;
		else
			data->sprite[i_spt].size = (data->m_width / data->sprite[i_spt].dis) * SQUARE_SIZE;
		// Calculate x and y offsets
		data->sprite[i_spt].y_off = data->m_height / 2 - data->sprite[i_spt].size / 2;
		data->sprite[i_spt].x_off = (DEG(spt_angle) - DEG(data->rotation_angle)) * data->m_width / DEG(FOV_ANGLE) + ((data->m_width / 2) - (data->sprite[i_spt].size / 2));
		draw_sprites(data, data->sprite[i_spt].x_off, data->sprite[i_spt].y_off, i_spt);
	}
}
int initialize_sprite(t_struct *data)
{
	int i;
	int j;
	int i_spt;

	i = 0;
	j = 0;
	i_spt = 0;
	if (!(data->sprite = (t_sprite *)malloc(sizeof(t_sprite) * (data->count_spt + 1))))
		return (0);
	while (data->map[i++][j])
	{
		while (data->map[i][j++])
		{
			if (data->map[i][j] == '2')
			{
				data->sprite[i_spt].x = (j + 0.5) * SQUARE_SIZE;
				data->sprite[i_spt].y = (i + 0.5) * SQUARE_SIZE;
				i_spt++;
			}
		}
	}
	return 0;
}
