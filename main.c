#include "cube3d.h"

int map[NUM_ROWS][NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 'N', 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	initialize_player(t_struct *data)
{
	data->bpp = 0;
	data->endian = 0;
	data->size_line = 1;
	data->mlx_ptr = NULL;
	data->img_ptr = NULL;
	data->win_ptr = NULL;
	data->img_data = NULL;
	data->move_step = 0;
	data->updated_player_x = 0;
	data->updated_player_y = 0;
	data->x = WINDOW_WIDTH / 2;
	data->y = WINDOW_HEIGHT / 2;
	data->radius = 10;
	data->width = 2;
	data->height = 2;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->rotation_angle = PI / 2;
	data->walk_speed = 50;
	data->turn_speed = 60 * (PI / 180);
}

int	render_map(t_struct *data)
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

	while (i < NUM_ROWS)
	{
		while (j < NUM_COLS)
		{
			square_x = j * SQUARE_SIZE;
			square_y = i * SQUARE_SIZE;
			square_color = map[i][j] != 0 ? 0xffffff : 0x000000;
			fill_square(square_x, square_y, SQUARE_SIZE, square_color, data);
			j++;
		}
		j = 0;
		i++;
	}
	draw_line(data);
	circle(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	move_player(data);
	return (TRUE);
}

void	draw_line(t_struct *data)
{
	int j;
	int i;

	j = 0;
	i = data->x;
	while(i++ < (data->x + (-1 * cos(data->rotation_angle) * 40)))
	{
		j = data->y - 64;
		while(j++ < (data->y + sin(data->rotation_angle) * 40) - 40)
			mlx_pixel_put(data->mlx_ptr, data->img_ptr, i, j , 0xff1100);
	}
}

void	fill_square(int square_x, int square_y, int tile_size, int tile_color, t_struct *data)
{
	int i;
	int j;

	i = square_x;
	j = 0;
	while(i++ < tile_size + square_x)
	{
		j = square_y;
		while (j++ < tile_size + square_y)
		{			
			mlx_pixel_put(data->mlx_ptr, data->img_ptr ,i, j , tile_color);
		}
	}
}

int	move_player(t_struct *data)
{
	data->rotation_angle += data->turn_direction * data->turn_speed;
	data->move_step = data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x + cos(data->rotation_angle) * data->move_step;
	data->updated_player_y = data->y + sin(data->rotation_angle) * data->move_step;

	data->x = data->updated_player_x;
	data->y = data->updated_player_y;
	return (TRUE);
}

int ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		key_pressed(int keycode, t_struct *data)
{
	if (keycode == 53)
		ft_close(data);
	if (keycode == 125)
		data->walk_direction = 1;
	if (keycode == 126)
		data->walk_direction = -1;
	if (keycode == 124)
		data->turn_direction = 1;
	if (keycode == 123)
		data->turn_direction = -1;
	return (keycode);
}

int		key_released(int keycode, t_struct *data)
{
	if (keycode == 126)
		data->walk_direction = 0;
	if (keycode == 125)
		data->walk_direction = 0;
	if (keycode == 123)
		data->turn_direction = 0;
	if (keycode == 124)
		data->turn_direction = 0;
	return (TRUE);
}
void	circle(t_struct *data)
{
	float two_pi;
	float i;
	float get_radius;

	two_pi = 2 * PI;
	i = 0;
	get_radius = data->radius;
	while(get_radius > 0)
	{
		i = 0;
		while (i <= two_pi)
		{
			mlx_pixel_put(data->mlx_ptr, data->img_ptr, (cos(i) * get_radius) + data->x, (sin(i) * get_radius) + data->y, 0xfcba03);
			i += 0.001;
		}
		get_radius-= 0.1;
	}

}

void            ft_draw(t_struct *data, int x, int y, int color)
{
	char    *dst;

	dst = data->img_data + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int initialize_window(t_struct *data)
{
	initialize_player(data);
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (FALSE);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube3d")) == NULL)
		return (FALSE);
	if ((data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT)) == NULL)
		return (FALSE);
	if ((data->img_data =  mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &data->endian)) == NULL)
		return (FALSE);
	mlx_hook(data->win_ptr,3,1L<<1,key_released, data);
	mlx_hook(data->win_ptr,2,1L<<0,key_pressed, data);
	mlx_loop_hook(data->mlx_ptr, render_map, data);
	mlx_loop(data->mlx_ptr);
	return (TRUE);
}

int main()
{
	t_struct *data;

	data = malloc(sizeof(t_struct));
	initialize_window(data);
	return 0;
}
