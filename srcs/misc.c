#include "../include/cub3d.h"

void	change_song(t_struct *data, int song_num)
{
    if (data->mu > 0)
        system("killall afplay 2&>/dev/null >/dev/null");
    if (song_num == 1)
        system("afplay songs/song1.mp3&");
    else if (song_num == 2)
        system("afplay songs/song2.mp3&");
    else if (song_num == 3)
        system("afplay songs/song3.mp3&");
    else if (song_num == 4)
        system("afplay songs/song4.mp3&");
}

/*
int		close_prog(t_var *v)
{
    mlx_destroy_img(v->mlx, v->ui);
    mlx_destroy_img(v->mlx, v->ps);
    mlx_destroy_img(v->mlx, v->ss);
    mlx_destroy_img(v->mlx, v->hr);
    mlx_destroy_img(v->mlx, v->wt);
    mlx_destroy_img(v->mlx, v->fl);
    mlx_destroy_img(v->mlx, v->cl);
    mlx_destroy_img(v->mlx, v->ui_t);
    mlx_destroy_img(v->mlx, v->hr_t);
    mlx_destroy_img(v->mlx, v->img);
    mlx_destroy_win(v->mlx, v->win);
    if (v->mu > 0)
        system("killall afplay 2&>/dev/null >/dev/null");
    free(v->name);
    free(v->map);
    free(v);
    exit(0);
    return (0);
}

 */