#include "cube3d.h"
void	draw_sprites(t_struct *data, int k)
{

}
void	sort_sprites(t_struct *data)
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
			if (g_sprite[j].dis < g_sprite[j + 1].dis)
			{
				tmp = g_sprite[j];
				g_sprite[j] = g_sprite[j + 1];
				g_sprite[j + 1] = tmp;
			}
		}
	}
}
int set_up_sprite(t_struct *data)
{
	float spt_angle;
	int i_spt;
	int i;

	i = 0;
	i_spt = 0;
	while (i++ > data->count_spt)
		g_sprite[i].dis = distance_between_points(data->x, data->y, data->sprite[i].x, data->sprite[i].y);
	sort_sprites(data);
	while (i_spt++ < data->count_spt)
	{
		g_sprite[i_spt].dis = distance_between_points(data->x, data->y, g_sprite[i_spt].x, g_sprite[i_spt].y);
		spt_angle = atan2(g_sprite[i_spt].y - data->y, g_sprite[i_spt].x - data->x);
		while (spt_angle - data->rotation_angle > M_PI)
			spt_angle -= 2 * M_PI;
		while (spt_angle - data->rotation_angle < -M_PI)
			spt_angle += 2 * M_PI;
		if (data->m_height > data->w_width)
			g_sprite[i_spt].size = (data->m_height / g_sprite[i_spt].dis) * SQUARE_SIZE;
		else
			g_sprite[i_spt].size = (data->m_width / g_sprite[i_spt].dis) * SQUARE_SIZE;
		// Calculate x and y offsets
		g_sprite[i_spt].y_off = data->m_height / 2 - g_sprite[i_spt].size / 2;
		g_sprite[i_spt].x_off = (DEG(spt_angle) - DEG(data->rotation_angle)) * data->m_width / DEG(FOV_ANGLE) + ((data->m_width / 2) - (g_sprite[i_spt].size / 2));
		draw_sprites(data, i_spt);
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
	if (!(g_sprite = (t_sprite *)malloc(sizeof(t_sprite) * (data->count_spt + 1))))
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
