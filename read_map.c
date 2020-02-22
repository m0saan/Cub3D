#include "cube3d.h"

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
int		check_boudded_map(t_struct *data)
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
			// if ((data->map[i][j] >= 0 || data->map[i][j] != 1 || data->map[i][j] != 2) || data->map[i][j] != 'N')
			// {
			// 	write(1,"Map containing unknown elements\n", 32);
			// 	return 0;
			// }
			if (data->map[i][0] != 1 || data->map[i][data->l_length - 1] != 1)
				return 0;
			if (data->map[0][j] != 1 || data->map[data->n_lines - 1][j] != 1)
			 	return 0;
			j++;
		}
		i++;
	}
	return 1;
}
int		mapito(t_struct *data, int *pos, char *buff)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	data->l_length = line_length(&buff[*pos]);
	data->n_lines = count_lines(&buff[*pos]);

	while (buff[*pos] != '\0' && i <data-> n_lines)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->l_length);
		buff[*pos] == '\n' ? (*pos += 1) : *pos;
		
		j = 0;
		while (j < data->l_length && buff[*pos] != '\n')
		{
			buff[*pos] == ' ' ? *pos += 1 : *pos;
			data->map[i][j] = ft_atoi(&buff[*pos]);
			j++;
			*pos += 1;
		}
		i++;
	}
	if (!(check_boudded_map(data)))
		return 0;
	return 1;
}
int read_map(t_struct *data, char *buff)
{
	int pos;
	int i;
	int get_to_map;

	pos = 0;
	i = 0;
	get_to_map = 0;
	while (buff[pos])
	{
		if (buff[pos] == 'R')
		{
			pos++;
			data->height = ft_atoi(&buff[pos++]);
			pos += skip_number(&buff[pos]);
			data->width = ft_atoi(&buff[pos]);
			get_to_map +=1;
		}
		if (buff[pos] == 'F')
		{
			pos++;
			data->f_red = ft_atoi(&buff[pos++]);
			pos += skip_number(&buff[pos]);
			data->f_green = ft_atoi(&buff[pos + 1]);
			pos += skip_number(&buff[pos]);
			data->f_blue = ft_atoi(&buff[pos + 1]);
			get_to_map +=1;
		}
		if (buff[pos] == 'C')
		{
			pos += 2;
			data->c_red = ft_atoi(&buff[pos]);
			pos += skip_number(&buff[pos]);
			data->c_green = ft_atoi(&buff[pos + 1]);
			pos += skip_number(&buff[pos]);
			data->c_blue = ft_atoi(&buff[pos + 1]);
			get_to_map +=1;
		}
		if (buff[pos] == 'N' && buff[pos + 1] == 'O')
		{
			while(buff[pos] != '.' && buff[pos + 1] != '/')
				pos++;
			while (buff[pos] != '\n')
			{
				data->path_to_the_north_texture[i] = buff[pos];
				i++;
				pos++;
			}
			get_to_map +=1;	
		}
		i = 0;
		if (buff[pos] == 'S' && buff[pos + 1] == 'O')
		{
			while(buff[pos] != '.' && buff[pos + 1] != '/')
				pos++;
			while (buff[pos] != '\n')
			{
				data->path_to_the_south_texture[i] = buff[pos];
				i++;
				pos++;
			}
			get_to_map +=1;	
		}
		if (buff[pos] == 'W' && buff[pos + 1] == 'E')
		{
			while(buff[pos] != '.' && buff[pos + 1] != '/')
				pos++;
			while (buff[pos] != '\n')
			{
				data->path_to_the_west_texture[i] = buff[pos];
				i++;
				pos++;
			}
			get_to_map +=1;
		}
		if (buff[pos] == 'E' && buff[pos + 1] == 'A')
		{
			while(buff[pos] != '.' && buff[pos + 1] != '/')
				pos++;
			while (buff[pos] != '\n')
			{
				data->path_to_the_east_texture[i] = buff[pos];
				i++;
				pos++;
			}
			get_to_map +=1;
		}
		if (buff[pos] == '1' && buff[pos + 1] == ' ' && buff[pos + 2] == '1' 
		&& get_to_map == 7)
		{
			if (!(mapito(data, &pos, buff)))
				{
					write(1, MAP_NOT_BOUNDED, 31);
					return 1;
				}
			break ;
		}
		pos++;
	}
	return 0;
}

int		parse(t_struct *data, char **av)
{
	int fd;
	int len = 1024;
	char *buff[len];
	ft_memset(buff, 0, len);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, len) < 0)
		return (0);
	if (!(ft_strchr((char *)buff, 'R')) || !(ft_strchr((char *)buff, 'F'))
	|| !(ft_strchr((char *)buff, 'C')) || !(ft_strchr((char *)buff, 'S')))
	{
		write(1, "Enough informations is not included!\n", 37);
		return 1;
	}
	if (read_map(data, (char *)buff))
		return 1;
	return (0);
}
void	initialize_file_struct(t_struct *data)
{
	data->fd = 0;
	data->line = NULL;
	data->width = 0;
	data->height = 0;
	data->f_red = 0;
	data->f_green = 0;
	data->f_blue = 0;
	data->c_red = 0;
	data->c_green = 0;
	data->c_blue = 0;
	data->map = malloc(sizeof(int) * 29);
	ft_memset(data->path_to_the_north_texture, 0, 100);
	ft_memset(data->path_to_the_south_texture, 0, 100);
	ft_memset(data->path_to_the_east_texture, 0, 100);
	ft_memset(data->path_to_the_west_texture, 0, 100);

}
int mainO(t_struct *data, char **av)
{
	initialize_file_struct(data);
	if (parse(data, av))
		return 1;
	return 0;
}