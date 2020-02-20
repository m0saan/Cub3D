#include "cube3d.h"
/*
int Map[NUM_ROWS][NUM_COLS];
static int		skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}
void	read_mapp(t_read *data, int pos)
{
	char **line;
	int i = 0;
	int j =0;
	
	if (data->line[pos] == '1')
	{
		while (i++ < NUM_ROWS)
		{
			j = 0;
			while (j++ < NUM_COLS)
				printf("%c\n", line[i][j]);
		}
		while (data->line[i])
		{
			while (j++ < NUM_COLS)
			{
				if (data->line[j] != ' ')
					Map[i][j] = data->line[j];
			}
			i++;
		}
	}
}
void read_map(t_read *data)
{
	int pos;

	pos = 0;
	data->fd = open("map.cub", O_RDONLY);
	while (get_next_line(data->fd, &data->line))
	{
		if (data->line[pos] == 'R')
		{
			pos++;
			data->height = ft_atoi(&data->line[pos++]);
			pos += skip_number(&data->line[pos]);
			data->width = ft_atoi(&data->line[pos]);
			pos = 0;
		}
		if (data->line[pos] == 'F')
		{
			pos++;
			data->f_red = ft_atoi(&data->line[pos++]);
			pos += skip_number(&data->line[pos]);
			data->f_green = ft_atoi(&data->line[pos + 1]);
			pos += skip_number(&data->line[pos]);
			data->f_blue = ft_atoi(&data->line[pos + 1]);
			pos = 0;
		}
		if (data->line[pos] == 'C')
		{
			pos += 2;
			data->c_red = ft_atoi(&data->line[pos]);
			pos += skip_number(&data->line[pos]);
			data->c_green = ft_atoi(&data->line[pos + 1]);
			pos += skip_number(&data->line[pos]);
			data->c_blue = ft_atoi(&data->line[pos + 1]);
		}
		pos = 0;
		read_mapp(data, pos);
	}
	
}
*/

int		count_lines(char *buff)
{
	int i;
	int num_lines;

	i = 0;
	num_lines = 0;
	while(buff[i])
	{
		if (buff[i] == '\n')
			num_lines += 1;
		i++;
	}
	return (num_lines);
}

int		line_length(char *line)
{
	int i;
	int length;
	
	i = 0;
	length = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ')
			length++;
		i++;
	}
	return (length);
}

int		parse(t_read *data, char **av)
{
	int fd;
	int len = 1024;
	char *buff[len];
	fd = open("map.cub", O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		return (0);
	printf("Number of lines : %d\n", count_lines((char *)buff));
	printf("line length : %d\n", line_length((char *)buff));
	printf("%s\n", (char *)buff);
}

int main(int argc, char **argv)
{
	t_read *data;
	parse(data, argv);
	return 0;
}
