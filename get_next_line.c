/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:32:03 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/12 22:21:01 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	tellsize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 10)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	char static	*vessel;
	int			i;

	if (!BUFFER_SIZE || fd == -1)
		return (0);
	buff = (char *) malloc (BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, 10))
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff [i] = '\0';
		if (i < 1)
		{
			if (vessel)
				return (vessel);
			free(buff);
			return (NULL);
		}
		vessel = ft_join(vessel, buff);
	}
	free (buff);
	line = ft_substr(vessel, 0, tellsize(vessel) + 1);
	ft_strcpy(vessel, vessel + tellsize(vessel) + 1);
	return (line);
}
