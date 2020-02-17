/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboustt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:32:38 by moboustt          #+#    #+#             */
/*   Updated: 2020/01/14 00:50:50 by moboustt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_d_shit(char **to_free)
{
	if (to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub_str;
	size_t		len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (!(sub_str = malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (s[start] != '\0' && i < len && start < len_s)
	{
		sub_str[i] = *(unsigned char *)(s + start);
		start++;
		i++;
	}
	sub_str[i] = '\0';
	return (char *)(sub_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_alloc;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	if (!(new_alloc = malloc(s1_len + s2_len + 1)))
		return (NULL);
	while (s1[i])
	{
		new_alloc[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		new_alloc[i] = s2[i - s1_len];
		i++;
	}
	free_d_shit(&s1);
	new_alloc[i] = '\0';
	return ((char *)new_alloc);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
