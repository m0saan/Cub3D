/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:10:12 by moboustt          #+#    #+#             */
/*   Updated: 2020/01/22 15:48:27 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#define PI 3.14159265359
#define NUM_RAYS 1080

#define TRUE 1
#define FALSE 0

#define SQUARE_SIZE 64
#define NUM_ROWS 14
#define NUM_COLS 29
#define FOV_ANGLE (60 * (PI / 180))

#define WINDOW_WIDTH (NUM_COLS * SQUARE_SIZE)
#define WINDOW_HEIGHT (NUM_ROWS * SQUARE_SIZE)

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <string.h>
#include <fcntl.h>

# define MAX_INT 2147483647
#define BUFFER_SIZE 90
typedef struct		s_struct
{
	int     		bpp;
	int     		size_line;
	int     		endian;
	void    		*mlx_ptr;
	void    		*img_ptr;
	void			*win_ptr;
	char    		*img_data;
	float			move_step;
	float			updated_player_x;
	float			updated_player_y;
	float			x;
	float			y;
	float			radius;
	float			width;
	float			height;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;

}					t_struct;
typedef struct		s_struc
{
	int fd;
	char *line;
	signed int width;
	signed int height;
	signed int f_red;
	signed int f_green;
	signed int f_blue;
	signed int c_red;
	signed int c_green;
	signed int c_blue;
}					t_read;
int		get_next_line(int fd, char **line);
void	free_d_shit(char **to_free);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		gnl_get_index(char *stack);
void	gnl_verify_line(char **line, char **stack, char **heap);
int		gnl_read_line(char **line, char **stack, char **heap, int byte, int fd);
int		ft_atoi(const char *s);
char	**ft_split(const char *ss, char c);
void	fill_square(int square_x, int square_y, int tile_size, int square_color, t_struct *data);
void	render_player(t_struct *data);
void	initialize_player(t_struct *data);
int		render_map(t_struct *data);
void	fill_square(int square_x, int square_y, int tile_size, int square_color, t_struct *data);
int		key_hook(int keycode,void *param);
int 	initialize_window(t_struct *data);
int		move_player(t_struct *data);
void	circle(t_struct *data);
void	draw_line(t_struct *data);
void	ft_draw(t_struct *data, int x, int y, int color);

#endif
