/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:23:48 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/14 18:23:51 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*vessel[1024];
	int			i;

	i = 1;
	while (i || !ft_strchr(vessel[fd], 10))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 1)
		{
			if (vessel[fd])
				break ;
			return (NULL);
		}
		buff [i] = '\0';
		vessel[fd] = ft_join(vessel[fd], buff);
		i = 0;
	}
	line = ft_substr(vessel[fd], 0, tellsize(vessel[fd]) + 1, 1);
	vessel[fd] = ft_substr(vessel[fd], tellsize(vessel[fd]) + 1,
			ft_strlen(vessel[fd]) + 1, 0);
	if (!ft_strlen(vessel[fd]))
		vessel[fd] = ft_free(vessel[fd]);
	return (line);
}
