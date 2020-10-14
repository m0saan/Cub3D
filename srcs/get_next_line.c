/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:43:56 by moboustt          #+#    #+#             */
/*   Updated: 2020/01/14 00:07:19 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int			gnl_get_index(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			gnl_handle_stack(char **line, char **stack, char **heap, int fd)
{
	if (fd < 0 || !line)
		return (-1);
	if (*stack)
	{
		if (gnl_get_index(*stack) > -1)
		{
			*heap = *stack;
			gnl_verify_line(line, stack, heap);
			free_d_shit(heap);
			return (1);
		}
		*line = ft_strdup(*stack);
		free_d_shit(stack);
	}
	return (0);
}

void		gnl_verify_line(char **line, char **stack, char **heap)
{
	int		index;
	char	*add;

	index = gnl_get_index(*heap);
	*stack = ft_strdup(&heap[0][index + 1]);
	add = ft_substr(*heap, 0, index);
	*line = ft_strjoin(*line, add);
	free_d_shit(heap);
	free_d_shit(&add);
}

int			get_next_line(int fd, char **line)
{
	static	char	*stack[1000];
	char			*heap;
	int				byte;

	*line = NULL;
	if ((byte = gnl_handle_stack(line, &stack[fd], &heap, fd)) == 1)
		return (1);
	if (*line == NULL)
		*line = ft_strdup("");
	if ((!(BUFFER_SIZE >= 0 && BUFFER_SIZE <= MAX_INT)) ||
	(!(heap = malloc(BUFFER_SIZE + 1 * sizeof(char)))))
		return (-1);
	while ((byte = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[byte] = '\0';
		if (gnl_get_index(heap) > -1)
		{
			gnl_verify_line(line, &stack[fd], &heap);
			return (1);
		}
		*line = ft_strjoin(*line, heap);
	}
	if (!byte)
		free_d_shit(&heap);
	return (byte > 0 ? 1 : byte);
}
