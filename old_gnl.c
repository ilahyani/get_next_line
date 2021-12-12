/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:55:12 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/09 22:43:50 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 

char	*get_next_line(int fd)
{
	char		*buff;
	char		*bytesread;
	static char	*vessel;

	if (!BUFFER_SIZE || fd == -1)
		return (NULL);
	buff = (char *) malloc (BUFFER_SIZE * sizeof(char) + 1);
	vessel = (char *) malloc (BUFFER_SIZE * sizeof(char) + 1);
	if (!buff || !vessel)
		return (NULL);
	bytesread = NULL;
	while (1)
	{
		if (read(fd, buff, BUFFER_SIZE))
		{
			*(buff + BUFFER_SIZE) = '\0';
			if (!bytesread)
				bytesread = ft_strdup(buff);
			else
				bytesread = ft_strjoin(bytesread, buff);
		}
		if (ft_strchr(buff, 10))
			break ;
	}
	delnl(bytesread, vessel);
//	printf("vessel: |%s|\n", vessel);
	free(buff);
	return (bytesread);
}
