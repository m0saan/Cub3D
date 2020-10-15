#include "../include/cube3d.h"

void draw_line(t_struct *data)
{
	float j;
	float i;
	float radius;

	i = data->x;
	j = data->y;
	radius = 40;
	while (radius > 0)
	{
		j = data->y;
		while (j++ < data->y + 1)
			ft_draw(data, (i + cos(data->rotation_angle) * radius) * MINI,
					(j + sin(data->rotation_angle) * radius) * MINI, 0x4287f5);
		radius -= 1;
	}
}

void circle(t_struct *data)
{
	float two_pi;
	float i;
	float get_radius;

	two_pi = 2 * PI;
	i = 0;
	get_radius = data->radius;
	while (get_radius > 0)
	{
		i = 0;
		while (i <= two_pi)
		{
			ft_draw(data, MINI * ((cos(i) * get_radius) + data->x),
					MINI * ((sin(i) * get_radius) + data->y), 0xfcba03);
			i += 0.1;
		}
		get_radius -= 0.1;
	}
}

void fill_square(int square_x, int square_y,
				 int tile_size, int tile_color, t_struct *data)
{
	int i;
	int j;

	i = square_x;
	j = 0;
	while (i++ < tile_size + square_x)
	{
		j = square_y;
		while (j++ < tile_size + square_y)
			ft_draw(data, i * MINI, j * MINI, tile_color);
	}
}

int render_map(t_struct *data, int m)
{
	int i;
	int j;
	int square_x;
	int square_y;
	int square_color;

	i = 0;
	j = 0;
	square_x = 0;
	square_y = 0;
	square_color = 0;

	while (i <= data->n_lines)
	{
		while (j < g_lines_length[i])
		{
			m = data->map[i][j];
			square_x = j * SQUARE_SIZE;
			square_y = i * SQUARE_SIZE;
			square_color = m != 0 ? GREEN : WHITE;
			if (m == 'N' || m == 'W' || m == 'E' || m == 'S')
				square_color = PLAYER;
			else if (m == 2)
				square_color = SPRITE;
			fill_square(square_x - 1, square_y - 1, SQUARE_SIZE, square_color, data);
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

void mini_map(t_struct *data)
{
	int m;
	render_map(data, m);
	circle(data);
	draw_line(data);
}
