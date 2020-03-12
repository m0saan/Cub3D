#include "cube3d.h"
static	void draw_sprites(t_struct *data, int index)
{
	int i;
	int j;
	int color;
	size_t size;

	i = 0;
	j = 0;
	size = data->sprite[index].size;
	while (i++ < size)
	{
		if (g_sprite[index].x_off + i < 0 || g_sprite[index].x_off + i > data->w_width)
			continue;
		if (g_rays[(int)(g_sprite[index].x_off + i)].distance <= data->sprite[index].dis)
			continue;
		j = 0;
		while (j++ < size)
		{
			if (g_sprite[index].y_off + j < 0 || g_sprite[index].y_off + j > data->w_height)
				continue ;
			color = data->sp[64 * (64 * j / size) + (64 * i / size)];
			ft_draw(data,i ,j ,color);
		}
	}
}
static void sort_sprites(t_struct *data)
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
void	set_up_sprite(t_struct *data)
{
	float spt_angle;
	int i_spt;
	int i;

	i = 0;
	i_spt = 0;
	printf("num_sprites : %d\n", data->count_spt);
	while (i < data->count_spt - 1)
	{
		printf("i : %d\n", i);
		g_sprite[i].dis = distance_between_points(data->x, data->y, data->sprite[i].x, data->sprite[i].y);
		i++;
	}
	sort_sprites(data);
	while (i_spt++ < data->count_spt)
	{
		g_sprite[i_spt].dis = distance_between_points(data->x, data->y, g_sprite[i_spt].x, g_sprite[i_spt].y);
		spt_angle = atan2(g_sprite[i_spt].y - data->y, g_sprite[i_spt].x - data->x);
		while (spt_angle - data->rotation_angle > M_PI)
			spt_angle -= 2 * M_PI;
		while (spt_angle - data->rotation_angle < -M_PI)
			spt_angle += 2 * M_PI;
		if (data->w_height > data->w_width)
			g_sprite[i_spt].size = (data->w_height / g_sprite[i_spt].dis) * SQUARE_SIZE;
		else
			g_sprite[i_spt].size = (data->w_width / g_sprite[i_spt].dis) * SQUARE_SIZE;
		// Calculate x and y offsets
		g_sprite[i_spt].y_off = data->w_height / 2 - g_sprite[i_spt].size / 2;
		g_sprite[i_spt].x_off = (deg(spt_angle) - deg(data->rotation_angle))
		* data->w_width / deg(FOV_ANGLE) + ((data->w_width / 2) - (g_sprite[i_spt].size / 2));
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
	if (!(data->sprite = (t_sprite *)malloc(sizeof(t_sprite) * (data->count_spt + 1))))
		return (0);
	while (i < 14)
	{
		j = 0;
		while (j < 29)
		{
			if (data->map[i][j] == 2)
			{
				printf("Yes!\n");
				data->sprite[i_spt].x = (j + 0.5) * SQUARE_SIZE;
				data->sprite[i_spt].y = (i + 0.5) * SQUARE_SIZE;
				i_spt++;
			}
			j++;
		}
		i++;
	}
	printf("i : %d\nj : %d\n", i,j);
	return 0;
}
