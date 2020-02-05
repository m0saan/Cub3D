#include "cube3d.h"
void	line(t_struct *data,  int X0, int Y0, int X1, int Y1);
int	map[NUM_ROWS][NUM_COLS] =
{
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
typedef	struct 		s_ray
{
	float	ray_angle;
	float	wall_h_x;
	float	wall_h_y;
	float	distance;
	int		wall_h_vert;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		wall_h_content;
}					t_ray[NUM_RAYS];
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
	data->walk_speed = 5;
	data->turn_speed = 3 * (PI / 180);
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
	data->save_vert_wall_hit_x = 0;
	data->save_vert_wall_hit_y = 0;
	data->horiz_touch_x = 0;
	data->horiz_touch_y = 0;
	data->vert_touch_x = 0;
	data->vert_touch_y = 0;
	data->found_horiz_wall_hit = FALSE;
	data->found_vert_wall_hit = FALSE;
	data->vert_wall_hit_content = FALSE;
}
float limit_angle(float angle) {
    angle = remainderf(angle, TWO_PI);
    if (angle < 0) {
        angle = TWO_PI + angle;
    }
    return angle;
}

float distance_between_points(float x1, float y1, float x2, float y2) 
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void	horizontal_ray_intersection(float ray_angle, t_struct *data)
{
	int horzWallContent = 0;

    data->y_intercept = floor(data->y / SQUARE_SIZE) * SQUARE_SIZE;
    data->y_intercept += data->is_ray_facing_down ? SQUARE_SIZE : 0;
    data->x_intercept = data->x + (data->y_intercept - data->y) / tan(ray_angle);
    data->dy = SQUARE_SIZE;
    data->dy  *= data->is_ray_facing_up ? -1 : 1;
    data->dx = SQUARE_SIZE / tan(ray_angle);
    data->dx *= (data->is_ray_facing_left && data->dx > 0) ? -1 : 1;
    data->dx *= (data->is_ray_facing_right && data->dx < 0) ? -1 : 1;
    data->horiz_touch_x = data->x_intercept;
    data->horiz_touch_y = data->y_intercept;

    while (data->horiz_touch_x >= 0 && data->horiz_touch_x <= WINDOW_WIDTH && data->horiz_touch_y >= 0 && data->horiz_touch_y <= WINDOW_HEIGHT) {
        float xToCheck = data->horiz_touch_x;
        float yToCheck = data->horiz_touch_y + (data->is_ray_facing_up ? -1 : 0);
        
        if (if_wall(xToCheck, yToCheck)) {
            // found a wall hit
            data->save_horiz_wall_hit_x = data->horiz_touch_x;
            data->save_horiz_wall_hit_y = data->horiz_touch_y;
            horzWallContent = map[(int)floor(yToCheck / SQUARE_SIZE)][(int)floor(xToCheck / SQUARE_SIZE)];
            data->found_horiz_wall_hit = TRUE;
            break;
        } else {
            data->horiz_touch_x += data->dx;
            data->horiz_touch_y += data->dy;
        }
    }
}
void	vertical_ray_intersection(float ray_angle, t_struct *data)
{
	int vert_wall_content;
	
	vert_wall_content = 0;
    data->x_intercept = floor(data->x / SQUARE_SIZE) * SQUARE_SIZE;
    data->x_intercept += data->is_ray_facing_right ? SQUARE_SIZE : 0;
    data->y_intercept = data->y + (data->x_intercept - data->x) * tan(ray_angle);
    data->dx = SQUARE_SIZE;
    data->dx *= data->is_ray_facing_left ? -1 : 1;
    data->dy = SQUARE_SIZE * tan(ray_angle);
    data->dy *= (data->is_ray_facing_up && data->dy > 0) ? -1 : 1;
    data->dy *= (data->is_ray_facing_down && data->dy < 0) ? -1 : 1;
    data->vert_touch_x = data->x_intercept;
    data->vert_touch_y = data->y_intercept;
    while (data->vert_touch_x >= 0 && data->vert_touch_x <= WINDOW_WIDTH && data->vert_touch_y >= 0 && data->vert_touch_y <= WINDOW_HEIGHT) {
        float xToCheck = data->vert_touch_x + (data->is_ray_facing_left ? -1 : 0);
        float yToCheck = data->vert_touch_y;
        if (if_wall(xToCheck, yToCheck)) {
            data->save_vert_wall_hit_x = data->vert_touch_x;
            data->save_vert_wall_hit_y = data->vert_touch_y;
            vert_wall_content = map[(int)floor(yToCheck / SQUARE_SIZE)][(int)floor(xToCheck / SQUARE_SIZE)];
            data->found_vert_wall_hit = TRUE;
            break;
        } else {
            data->vert_touch_x += data->dx;
            data->vert_touch_y+= data->dy;
        }
    }
}
void	fill_out_ray(int ray_id, float ray_angle, t_struct *data, t_ray *rays)
{
	float horz_hit_distance;
	float vert_hit_distance;

    horz_hit_distance = data->found_horiz_wall_hit
        ? distance_between_points(data->x, data->y, data->save_horiz_wall_hit_x, data->save_horiz_wall_hit_y)
        : MAX_INT;
    vert_hit_distance = data->found_vert_wall_hit
        ? distance_between_points(data->x, data->y, data->save_vert_wall_hit_x, data->save_vert_wall_hit_y)
        : MAX_INT;
    if (vert_hit_distance < horz_hit_distance) 
	{
        rays[ray_id]->distance = vert_hit_distance;
        rays[ray_id]->wall_h_x = data->save_vert_wall_hit_x;
        rays[ray_id]->wall_h_y = data->save_vert_wall_hit_y;
        //rays[ray_id]->wallHitContent = vertWallContent;
        //rays[ray_id]->wasHitVertical = TRUE;
    }
	else
	{
        rays[ray_id]->distance = horz_hit_distance;
        rays[ray_id]->wall_h_x = data->save_horiz_wall_hit_x;
        rays[ray_id]->wall_h_y = data->save_horiz_wall_hit_y;
        //rays[ray_id]->wallHitContent = horzWallContent;
        //rays[ray_id]->wasHitVertical = FALSE;
    }
    rays[ray_id]->ray_angle = ray_angle;
    rays[ray_id]->is_ray_facing_down = data->is_ray_facing_down;
    rays[ray_id]->is_ray_facing_up = data->is_ray_facing_up;
    rays[ray_id]->is_ray_facing_left = data->is_ray_facing_left;
    rays[ray_id]->is_ray_facing_right = data->is_ray_facing_right;
}
void cast_single_ray(int ray_id, float ray_angle,t_struct *data,t_ray *rays) 
{
    ray_angle = limit_angle(ray_angle);
    data->is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
    data->is_ray_facing_up = !(data->is_ray_facing_down);
    data->is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
   	data->is_ray_facing_left = !(data->is_ray_facing_right);
	horizontal_ray_intersection(ray_angle, data);
	vertical_ray_intersection(ray_angle, data);
	fill_out_ray(ray_id, ray_angle, data, rays);
}

void	render_all_rays(t_struct *data, t_ray *rays)
{
	int i;

	i = 0;
	while (i < 1)
	{
		line(data, data->x, data->y, rays[i]->wall_h_x, rays[i]->wall_h_y);
		i++;
	}
}

void	cast_rays(t_struct *data)
{
	t_ray rays[NUM_RAYS];
	int ray_id;
	int i;
	float ray_angle;

	ray_id = 0;
	i = 0;
	ray_angle = data->rotation_angle - (FOV_ANGLE / 2);
	while (i < 1)
	{
		cast_single_ray(ray_id, ray_angle, data, rays);
		i++;
		ray_angle += FOV_ANGLE / NUM_RAYS;
		ray_id++;
	}
	render_all_rays(data, rays);
}
void	draw_line(t_struct *data)
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
			ft_draw(data, i + cos(data->rotation_angle) * radius , j + sin(data->rotation_angle) * radius , 0x4287f5);
	radius -= 1;
	}
}
int		update(t_struct *data)
{
	render_map(data);
	circle(data);
	draw_line(data);
	cast_rays(data);
	move_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (TRUE);
}

int	if_wall(float x, float y)
{
	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return TRUE;
	int map_index_x = floor((x / 64));
	int map_index_y = floor((y / 64));
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

void	line(t_struct *data,int X0, int Y0, int X1, int Y1) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        ft_draw (data, X,Y,0xff1100);  // put pixel at (X,Y) 
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
        //delay(100);          // for visualization of line- 
                             // generation step by step 
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
			i += 0.1;
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
