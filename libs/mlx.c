#include <mlx.h>

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             main(void)
{
	int i = 0;
	int j = 0;
	void    *mlx;
	void    *mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Test");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	while (i++ < 599)
	{
		j = 0;
		while (j++ < 599)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
