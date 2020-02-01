#include "cube3d.h"

int	map[NUM_ROWS][NUM_COLS] = {
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
	data->width = 6;
	data->height = 6;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->rotation_angle = PI / 2;
	data->walk_speed = 10;
	data->turn_speed = 20 * (PI / 180);
	data->is_ray_facing_down = 0;
	data->is_ray_facing_up = 0;
	data->is_ray_facing_right = 0;
	data->is_ray_facing_left = 0;
	data->dx = 0;
	data->dy = 0;
	data->x_intercept = 0;
	data->y_intercept = 0;
	data->save_horiz_wall_hit_x = 0;
	data->save_horiz_wall_hit_y = 0;
	data->horiz_touch_x = 0;
	data->horiz_touch_y = 0;
	data->found_horiz_wall_hit = FALSE;
}
float	limit_ray_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, (PI * 2));
	if (ray_angle < 0)
		ray_angle += (PI * 2);
	return ray_angle;
}
void	cast_single_ray(int	colm_n, float	ray_angle, t_struct *data)
{
	ray_angle = limit_ray_angle(ray_angle);
	data->is_ray_facing_down = ray_angle >= 0 && ray_angle <= PI;
	data->is_ray_facing_up = !data->is_ray_facing_down;
	data->is_ray_facing_right = ray_angle >= (PI / 2) || ray_angle <= (3/2 * PI);
	data->is_ray_facing_left = !data->is_ray_facing_right;

	data->y_intercept = (int)(data->y / SQUARE_SIZE) * SQUARE_SIZE;
	data->y_intercept += data->is_ray_facing_down ? SQUARE_SIZE : 0;

	data->x_intercept = data->x + (data->y - data->y_intercept) / tan(ray_angle);

	data->dy = SQUARE_SIZE;
	data->dy *= data->is_ray_facing_up ? -1: 1;

	data->dx = 1/tan(ray_angle) * data->dy;
	data->dx *= (data->is_ray_facing_left && data->dx > 0) ? -1 : 1;
	data->dx *= (data->is_ray_facing_right && data->dx < 0) ? -1 : 1;

	data->horiz_touch_x = data->x_intercept;
	data->horiz_touch_y = data->y_intercept;

	if (data->is_ray_facing_up)
		data->is_ray_facing_up--;
	while (data->horiz_touch_x >= 0 && data->horiz_touch_y < WINDOW_WIDTH
			&& data->horiz_touch_y >= 0 && data->horiz_touch_y < WINDOW_HEIGHT)
	{
		if (if_wall(data->horiz_touch_x, data->horiz_touch_y))
		{
			data->found_horiz_wall_hit = TRUE;
			data->save_horiz_wall_hit_x = data->horiz_touch_x;
			data->save_horiz_wall_hit_y = data->horiz_touch_y;
			draw_line(data, data->save_horiz_wall_hit_x, data->save_horiz_wall_hit_y, ray_angle);
			break;
		}
		else
		{
			data->horiz_touch_x += data->dx;
			data->horiz_touch_y += data->dy;
		}
	}
}

void	cast_rays(t_struct *data)
{
	int colm_n;
	int i;
	float ray_angle;

	colm_n = 0;
	i = 0;
	ray_angle = data->rotation_angle - (FOV_ANGLE / 2);
	while (i < 2)
	{
		cast_single_ray(colm_n, ray_angle, data);
		i++;
		ray_angle += FOV_ANGLE / NUM_RAYS;
		colm_n++;
	}
}

int		update(t_struct *data)
{
	render_map(data);
	//draw_line(data);
	circle(data);
	move_player(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (TRUE);
}

int	if_wall(float x, float y)
{
	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return TRUE;
	int map_index_x = (int)(x / 64);
	int map_index_y = (int)(y / 64);
	return map[map_index_y][map_index_x] != 0;
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
			square_color = map[i][j] != 0 ? 0x2ecc71 : 0xecf0f1;
			fill_square(square_x - 1 , square_y - 1, SQUARE_SIZE, square_color, data);
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

void	draw_line(t_struct *data, float wall_hit_x, float wall_hit_y, float ray_angle)
{
	float j;
	float i;
	float radius;

	i = data->x;
	j = data->y;
	radius = wall_hit_x - data->x;
	radius < 0 ? radius *= -1 : 1; 
	while (radius > 0)
	{
		j = data->y;
		while (j++ < data->y + 1)
			ft_draw(data, i + cos(ray_angle) * radius , j + sin(ray_angle) * radius , 0xff1100);
	radius -= 0.5;
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
			ft_draw(data ,i, j , tile_color);
	}
}

int	move_player(t_struct *data)
{
	data->rotation_angle += data->turn_direction * data->turn_speed;
	data->move_step = data->walk_direction * data->walk_speed;
	data->updated_player_x = data->x + cos(data->rotation_angle) * data->move_step;
	data->updated_player_y = data->y + sin(data->rotation_angle) * data->move_step;
	if (!if_wall(data->updated_player_x, data->updated_player_y))
	{
		data->x = data->updated_player_x;
		data->y = data->updated_player_y;
	}

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
	if (keycode == 126)
		data->walk_direction = 1;
	if (keycode == 125)
		data->walk_direction = -1;
	if (keycode == 124)
		data->turn_direction = 1;
	if (keycode == 123)
		data->turn_direction = -1;
	return (TRUE);
}

int		key_released(int keycode, t_struct *data)
{
	if (keycode == 126)
		data->walk_direction = 0;
	if (keycode == 125)
		data->walk_direction = 0;
	if (keycode == 124)
		data->turn_direction = 0;
	if (keycode == 123)
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
			ft_draw(data, (cos(i) * get_radius) + data->x, (sin(i) * get_radius) + data->y, 0xfcba03);
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
	mlx_loop_hook(data->mlx_ptr, update, data);
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
