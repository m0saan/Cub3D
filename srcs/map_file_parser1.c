/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_parser1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:29:13 by moboustt          #+#    #+#             */
/*   Updated: 2020/02/24 18:29:15 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int count_lines(char *buff)
{
    int i;
    int num_lines;

    i = 0;
    num_lines = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
            num_lines += 1;
        i++;
    }
    return (num_lines);
}

int line_length(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    return (i);
}

int check_boudded_map(t_struct *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 14)
    {
        j = 0;
        while (j < 29)
        {
            if (data->map[i][j] == 78)
            {
                data->x = i * SQUARE_SIZE;
                data->y = j * SQUARE_SIZE;
            }
            if (data->map[i][0] != 1 || data->map[i][data->l_length - 1] != 1)
                return (0);
            if (data->map[0][j] != 1 || data->map[data->n_lines - 1][j] != 1)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_not_valid_element(t_struct *data, char *buff)
{
    return buff[data->pos] != '1' && buff[data->pos] != '0' && buff[data->pos] != '2' && buff[data->pos] != 'N' && buff[data->pos] != 'W' && buff[data->pos] != 'E' && buff[data->pos] != 'S' && buff[data->pos] != ' ';
}

int is_player(t_struct *data, char *buff)
{
    return buff[data->pos] == 'N' || buff[data->pos] == 'W' || buff[data->pos] == 'E' || buff[data->pos] == 'S';
}

int fill_out_map(t_struct *data, char *buff)
{
    int i;
    int j;
    int item;
    int **tmp;

    i = -1;
    data->n_lines = count_lines(&buff[data->pos]);
    g_lines_length = (int *)malloc((data->n_lines + 1) * sizeof(int));
    data->map = (char **)malloc((data->n_lines + 1) * sizeof(char *));
    while (buff[data->pos] != '\0' && i++ < data->n_lines)
    {
        data->l_length = line_length(&buff[data->pos]);
        g_lines_length[i] = data->l_length;
        data->map[i] = (char *)malloc(sizeof(char) * data->l_length);
        buff[data->pos] == '\n' ? (data->pos += 1) : data->pos;
        j = 0;
        while (j < data->l_length && buff[data->pos] != '\n')
        {
            if (is_not_valid_element(data, buff))
                return (1);
            if (is_player(data, buff))
            {
                data->i = i;
                data->j = j;
                data->map[i][j++] = data->orientation = buff[data->pos];
                init_player(data);
                data->pos += 1;
                continue;
            }
            data->map[i][j] = buff[data->pos];
            data->pos += 1;
            j++;
        }
        data->pos += 1;
    }
    //return (!(check_boudded_map(data)) ? 0 : 1);
    return 1;
}

void initialize_file_struct(t_struct *data)
{
    data->pos = 0;
    data->get_to_map = 0;
    data->width = 0;
    data->height = 0;
    data->f_red = 0;
    data->f_green = 0;
    data->f_blue = 0;
    data->c_red = 0;
    data->c_green = 0;
    data->c_blue = 0;
    data->map = malloc(sizeof(int) * 30);
    ft_memset(data->no, 0, 25);
    ft_memset(data->so, 0, 25);
    ft_memset(data->ea, 0, 25);
    ft_memset(data->we, 0, 25);
    ft_memset(data->sp, 0, 25);
}
