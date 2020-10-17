#include "../include/cube3d.h"

void			scrn_data(t_data *data, int x)
{
    creatergb()
    g_color = colorconverter(data->img.data[data->screen.row *
                                            data->screen.width + data->screen.col]);
    data->screen.buf[x * data->screen.width_in_bytes
                   + data->screen.col * 3 + 0] = g_color.b;
    data->screen.buf[x * data->screen.width_in_bytes
                   + data->screen.col * 3 + 1] = g_color.g;
    data->screen.buf[x * data->screen.width_in_bytes
                   + data->screen.col * 3 + 2] = g_color.r;
}

int				screen(t_struct *data)
{
    int				x;
    unsigned char	header[54];
    int				i;

    i = 0;
    while (i < 54)
        header[i++] = 0;
    //screen_init(data, header);
    data->screen.buf = malloc((data->screen.imagesize));
    x = 0;
    data->screen.row = data->screen.height - 1;
    while (data->screen.row-- >= 0)
    {
        data->screen.col = 0;
        while (data->screen.col++ < data->screen.width)
            //scrn_data(data, x);
        x++;
    }
    data->screen.fd = open(S, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    write(data->screen.fd, header, 54);
    write(data->screen.fd, (char*)data->screen.buf, data->screen.imagesize);
    close(data->screen.fd);
    free(data->screen.buf);
    return (0);
}