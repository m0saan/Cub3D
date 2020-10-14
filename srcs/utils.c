/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:56:28 by moboustt          #+#    #+#             */
/*   Updated: 2020/01/14 15:43:43 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static	int	ft_res(char const *str, int i)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		rc;
	char	*str;

	i = 0;
	rc = 0;
	str = (char *)s;
	if (!*str)
		return (0);
	while ((str[i] >= 0 && str[i] <= 26) || (str[i] >= 28 && str[i] <= 32))
		i++;
	if (str[i] == '-')
		rc = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (rc == 1)
		return (-ft_res(str, i));
	return (ft_res(str, i));
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

void		*ft_memset(void *b, int c, size_t len)
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

int			skip_number(const char *str)
{
	int i;

	i = 0;
	if (str[i] == ',' || str[i] == ' ')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && (str[i] != ' ' || str[i] != ','))
		i++;
	return (i);
}
