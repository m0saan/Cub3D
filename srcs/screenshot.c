
#include "../include/cube3d.h"

t_rgb *rgb;

t_rgb *color_converter(int hex_value)
{
    t_rgb *rgb_color = malloc(sizeof(t_rgb));

    rgb_color->r = ((hex_value >> 16) & 0xFF);
    rgb_color->g = ((hex_value >> 8) & 0xFF);
    rgb_color->b = ((hex_value)&0xFF);
    return (rgb_color);
}

int screen(t_struct *data)
{
    int x;
    const char *file_name = "screenshot.bmp";
    const int LEN = 54;
    unsigned char header[LEN];

    ft_memset(header, 0, LEN);
    screen_init(data, header);
    data->screen.buf = malloc((data->screen.image_size));
    x = 0;
    data->screen.row = data->screen.height - 1;
    while (data->screen.row-- >= 0)
    {
        data->screen.col = 0;
        while (data->screen.col < data->screen.width - 1) {
            screen_data(data, x);
            //printf("%d\n", data->screen.col);
            data->screen.col++;
        }
        x++;
    }
    data->screen.fd = open(file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    write(data->screen.fd, header, LEN);
    write(data->screen.fd, (char *)data->screen.buf, data->screen.image_size);
    close(data->screen.fd);
    free(data->screen.buf);
    return (0);
}

void screen_data(t_struct *data, int x)
{
    int index = data->screen.row * data->screen.width + data->screen.col;
    index = index < 0 ? index * (-1) : index;
    rgb = color_converter(data->img_data[index]);
    data->screen.buf[x * data->screen.width_in_bytes + data->screen.col * 3 + 0] = rgb->b;
    data->screen.buf[x * data->screen.width_in_bytes + data->screen.col * 3 + 1] = rgb->g;
    data->screen.buf[x * data->screen.width_in_bytes + data->screen.col * 3 + 2] = rgb->r;
}

void screen_init(t_struct *data, unsigned char *header)
{
    data->screen.width = (int32_t)data->w_width;
    data->screen.height = (int32_t)data->w_height;
    data->screen.bit_count = 24;
    data->screen.width_in_bytes = ((data->screen.width *
                                        data->screen.bit_count +
                                    31) /
                                   32) *
                                  4;
    data->screen.image_size = data->screen.width_in_bytes * data->screen.height;
    data->screen.bi_size = 40;
    data->screen.bf_off_bits = 54;
    data->screen.file_size = 54 + data->screen.image_size;
    data->screen.biplanes = 1;
    ft_mem_cpy(header, "BM", 2);
    ft_mem_cpy(header + 2, &(data->screen.file_size), 4);
    ft_mem_cpy(header + 10, &(data->screen.bf_off_bits), 4);
    ft_mem_cpy(header + 14, &(data->screen.bi_size), 4);
    ft_mem_cpy(header + 18, &(data->screen.width), 4);
    ft_mem_cpy(header + 22, &(data->screen.height), 4);
    ft_mem_cpy(header + 26, &(data->screen.biplanes), 2);
    ft_mem_cpy(header + 28, &(data->screen.bit_count), 2);
    ft_mem_cpy(header + 34, &(data->screen.image_size), 4);
}
