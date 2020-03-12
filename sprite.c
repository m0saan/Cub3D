#include "cube3d.h"
int		set_up_sprite(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->count_spt-- > 0)
	{
		data->sprite[i].x = 
	}

}
int		initialize_sprite(t_struct *data)
{
	int i;
	int j;
	int i_spt;

	i = 0;
	j = 0;
	i_spt = 0;
	if (!(data->sprite = (t_sprite*)malloc(sizeof(t_sprite) * (data->count_spt + 1))))
		return (0);
	while (data->map[i++][j])
	{
		while (data->map[i][j++])
		{
			if (data->map[i][j] == '2')
			{
				data->sprite[i_spt].x = (j + 0.5) * SQUARE_SIZE;
				data->sprite[i_spt].y = (i + 0.5) * SQUARE_SIZE;
				i_spt++;
			}
		}
	}
	return 0;
}