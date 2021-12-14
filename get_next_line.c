/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:32:03 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/14 11:50:27 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	tellsize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	return (i);
}

void	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*vessel;
	int			i;

	i = 1;
	while (i || !ft_strchr(vessel, 10))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 1)
		{
			if (vessel)
				break ;
			return (NULL);
		}
		buff [i] = '\0';
		vessel = ft_join(vessel, buff);
		i = 0;
	}
	line = ft_substr(vessel, 0, tellsize(vessel) + 1, 1);
	vessel = ft_substr(vessel, tellsize(vessel) + 1, ft_strlen(vessel) + 1, 0);
	if (!ft_strlen(vessel))
		vessel = ft_free(vessel);
	return (line);
}
