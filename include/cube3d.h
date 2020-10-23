/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:10:12 by moboustt          #+#    #+#             */
/*   Updated: 2020/10/23 09:59:30 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libs/OpenGL/mlx.h"
# include "../libft/libft.h"

# define BLACK 0x000000

# define PI 3.14159265359F
# define TWO_PI 2 * PI
# define DEG(x) x * 180 / M_PI
# define RAD(x) x *M_PI / 180

# define TRUE 1
# define FALSE 0

# define SQUARE_SIZE 512
# define TEX_WIDTH SQUARE_SIZE
# define TEX_HEIGHT SQUARE_SIZE
# define SPRITE_SIZE 64

# define FOV_ANGLE (60 * (PI / 180))

# define MAX_INT 2147483647

typedef unsigned char	uc;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_bitmap
{
	uint16_t	bit_per_pxl;
	int			width_in_pxl;
	uint32_t	info_header_size;
	uint32_t	image_size;
	uint32_t	bf_off_bits;
	uint32_t	file_size;
	uint16_t	biplanes;
	uc			*buf;
	int			fd;
	int			row;
	int			col;
}				t_bitmap;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		x_off;
	float		y_off;
	float		size;
	float		dis;
}				t_sprite;

typedef struct	s_ray
{
	float		ray_angle;
	float		wall_h_x;
	float		wall_h_y;
	float		distance;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_right;
	int			is_ray_facing_left;
	int			was_hit_vertical;
}				t_ray;

t_ray			*g_rays;
int				g_screenshot;
int				*g_lines_length;

typedef struct	s_struct
{
	int			t;
	int			orientation;
	int			bpp;
	int			size_line;
	int			endian;
	int			bpp_text;
	int			size_line_text;
	int			endian_text;
	int			*img_tex1;
	int			*img_tex2;
	int			*img_tex3;
	int			*img_tex4;
	void		*xpm_ptr1;
	void		*xpm_ptr2;
	void		*xpm_ptr3;
	void		*xpm_ptr4;
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			*img_data_bmp;
	char		*img_data;
	float		move_step;
	float		updated_player_x;
	float		updated_player_y;
	float		x;
	float		y;
	int			turn_direction;
	int			walk_direction;
	float		rotation_angle;
	float		walk_speed;
	float		turn_speed;

	float		dx;
	float		dy;
	float		ray_angle;
	float		x_intercept;
	float		y_intercept;
	float		save_horiz_wall_hit_x;
	float		save_horiz_wall_hit_y;
	float		save_vert_wall_hit_x;
	float		save_vert_wall_hit_y;
	int			vert_wall_hit_content;
	float		horz_hit_distance;
	float		vert_hit_distance;
	int			is_ray_facing_down;
	int			is_ray_facing_up;
	int			is_ray_facing_right;
	int			is_ray_facing_left;

	float		corrected_dsitance;
	float		top_pixel;
	float		bottom_pixel;
	float		distance_to_projection_plane;
	float		wall_height;
	int			i_wall_index;
	int			txt_offset_x;
	int			txt_offset_y;

	float		vert_touch_x;
	float		vert_touch_y;
	float		horiz_touch_x;
	float		horiz_touch_y;
	int			m_height;

	float		x_horz_to_check;
	float		y_horz_to_check;
	float		x_vert_to_check;
	float		y_vert_to_check;

	void		*sprite_xpm;
	int			*sprite_tex_data;

	int			n_lines;
	int			l_length;
	int			pos;
	int			get_to_map;
	signed int	w_width;
	signed int	w_height;
	signed int	f_red;
	signed int	f_green;
	signed int	f_blue;
	signed int	c_red;
	signed int	c_green;
	signed int	c_blue;
	char		no[15];
	char		so[15];
	char		we[15];
	char		ea[15];
	char		sp[15];
	char		**map;
	int			i_player;
	int			j_player;
	int         is_multi_player;

	int			count_spt;
	t_sprite	*sprite;
	t_bitmap	bitmap;
}				t_struct;

int				set_up_window(t_struct *data);
uint32_t		create_rgb(int r, int g, int b);
void			set_up_data(t_struct *data);
void			init_ray_cast_data(t_struct *data);
int				initialize_window(t_struct *data);
int				move_player(t_struct *data);
void			ft_draw(t_struct *data, int x, int y, int color);
int				if_wall(float x, float y, t_struct *data);
float			limit_angle(float angle);
float			distance_between_points(float x1, float y1,
				float x2, float y2);
void			horizontal_ray_intersection(float ray_angle, t_struct *data,
				int *found_horiz_wall_hit);
void			vertical_ray_intersection(float ray_angle, t_struct *data,
				int *found_vert_wall_hit);
void			cast_single_ray(int ray_id, float ray_angle,
				t_struct *data);
void			fill_out_ray(int ray_id, t_struct *data);
void			cast_rays(t_struct *data);
int				update(t_struct *data);
int				ft_close(void *param);
int				key_pressed(int keycode, t_struct *data);
int				key_released(int keycode, t_struct *data);
void			texture_from_file(t_struct *data);
void			render_walls(t_struct *data);
int				parse(t_struct *data, char **av);
void			initialize_file_struct(t_struct *data);
int				read_map(t_struct *data, char *buff);
void			fill_out_map(t_struct *data, char *buff);
int				line_length(const char *line);
int				count_lines(const char *buff);
void			get_western_texture_path(t_struct *data, const char *buff);
void			get_easter_texture_path(t_struct *data, const char *buff);
void			get_resolution_values(t_struct *data, char *buff);
void			get_floor_values(t_struct *data, char *buff);
void			get_ceilling_values(t_struct *data, char *buff);
void			get_north_texture_path(t_struct *data, const char *buff);
void			get_south_texture_path(t_struct *data, const char *buff);
int				skip_number(const char *str);
int				check_textures_f_c_s_availibility(char *buff);
void			get_sprite_path(t_struct *data, char *buff);
int				screw_this_norminette(t_struct *data, char *buff);
void			initialize_sprite(t_struct *data);
void			set_up_sprite(t_struct *data);
void			draw_sprites(t_struct *data, float x_off, float y_off,
				int index);
void			init_player(t_struct *data);
void			set_up_player(t_struct *data, int e);
int				is_sprite(char c);
int				is_player(t_struct *data, const char *buff);
int				calculate_index(float value);
int				is_not_valid_element(t_struct *data, const char *buff);
int				valid_indices(t_struct *data, int x, int y);
int				screen(t_struct *data);
void			screen_data(t_struct *data, int x);
void			screen_init(t_struct *data, unsigned char *header);
void			*ft_mem_cpy(void *dest, const void *src, size_t n);
int				destruct(t_struct *data);
void			error(char *str);
t_rgb			*color_converter(int hex_value);
float			calculate_y_offset(const t_struct *data, int y);
int				calculate_x_offset(const t_struct *data);
void			draw_ceilling(t_struct *data, int ceilling);
void			draw_floor(t_struct *data, int floor);
void			draw_walls(t_struct *data, float y);
int				*which_texture(const t_struct *data);
void			ft_ljodran(t_struct *data, int y);
int				normalize_index(int index);
int				get_color_index(t_struct *data);
void			set_sprite_coordinates(t_struct *data, int *i_spt, int i, int j);
void			set_sprite_distance(t_struct *data, int *i);
float			calc_sprite_y_offset(t_struct *data, int i_spt);
float			calc_sprite_x_offset(t_struct *data, int i_spt, float spt_angle);
void			swap(t_struct *data, int j);
void			bubble_sort(t_struct *data);
int				get_color_id(int i, int j, int size);
void			normalize_sprite_angle(t_struct *data, float *spt_angle);
void			normalize_sprite_size(t_struct *data, int *i_spt);
int				is_not_valid_xpm(t_struct *data);
int             value_at(int i, int j, t_struct *data);
int             check_element(t_struct *data, int i, int j);
void            check_map(t_struct *data);
int             is_valid_texture(t_struct *data, const char *buff);
int             is_negative(int v);
int             is_valid_color(const t_struct *data, int id);
int             not_valid_x_offset(const t_struct *data, float x_off, size_t i);
int             not_valid_distance(const t_struct *data, float x_off, int index, size_t i);
int             not_valid_y_offset(const t_struct *data, float y_off, size_t j);
#endif
