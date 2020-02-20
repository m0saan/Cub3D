#include "cube3d.h"

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
void read_map(t_read *data, char *buff)
{
	int pos;
	int i;

	pos = 0;
	i = 0;
	while (buff[pos])
	{
		if (buff[pos] == 'R')
		{
			pos++;
			data->height = ft_atoi(&buff[pos++]);
			pos += skip_number(&buff[pos]);
			data->width = ft_atoi(&buff[pos]);
		}
		if (buff[pos] == 'F')
		{
			pos++;
			data->f_red = ft_atoi(&buff[pos++]);
			pos += skip_number(&buff[pos]);
			data->f_green = ft_atoi(&buff[pos + 1]);
			pos += skip_number(&buff[pos]);
			data->f_blue = ft_atoi(&buff[pos + 1]);
		}
		if (buff[pos] == 'C')
		{
			pos += 2;
			data->c_red = ft_atoi(&buff[pos]);
			pos += skip_number(&buff[pos]);
			data->c_green = ft_atoi(&buff[pos + 1]);
			pos += skip_number(&buff[pos]);
			data->c_blue = ft_atoi(&buff[pos + 1]);
		}
		if (buff[pos] == 'N' && buff[pos + 1] == 'O')
		{
			if (buff[pos] == ' ')
				pos++;
			if (buff[pos] == '.' && buff[pos + 1] == '/')
				data->path_to_the_north_texture = &buff[pos];
		}
		pos++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*bb;

	i = 0;
	bb = b;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (bb);
}

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
	ft_memset(buff, 0, len);
	fd = open("map.cub", O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		return (0);
	read_map(data, (char *)buff);
	printf("Number of lines : %d\n", count_lines((char *)buff));
	printf("line length : %d\n", line_length((char *)buff));
	printf("%s\n", (char *)buff);
	return (1);
}

int main(int argc, char **argv)
{
	t_read *data;
	data = malloc(sizeof(t_read));
	parse(data, argv);
	printf("Height : %d\n", data->height);
	printf("Height : %d\n", data->width);
	printf("----------------------------------\n");
	printf("Height : %d\n", data->c_red);
	printf("Height : %d\n", data->c_green);
	printf("Height : %d\n", data->c_blue);
	printf("----------------------------------\n");
	printf("Height : %d\n", data->f_red);
	printf("Height : %d\n", data->f_green);
	printf("Height : %d\n", data->f_blue);
	printf("----------------------------------\n");
	printf("NO : %s\n", data->path_to_the_north_texture);
	return 0;
}
