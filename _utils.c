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

#include "cube3d.h"

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

char	*ft_strchr(const char *s, int c)
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