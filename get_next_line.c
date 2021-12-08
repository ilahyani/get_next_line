/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:55:12 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/08 19:32:03 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 

void	delnl(char	*str)
{
	int	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	while(str[i])
		str[i++] = '\0';
}

/*void	ft_fill(char *bytesread, char *buff)
{
	if (!bytesread)
		bytesread = ft_strdup(buff);
	else
		bytesread = ft_strjoin(bytesread, buff);
}
*/
char	*get_next_line(int fd)
{
	char		*buff;
	static char	*bytesread;
	int			f;

	if (!BUFFER_SIZE || !fd)
		return (NULL);
	bytesread = NULL;
	buff = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	f = 0;
	while (f == 0)
	{
		read(fd, buff, BUFFER_SIZE);
		if (!ft_strchr(buff, 10))
		{
//			ft_fill(bytesread, buff);
			if (!bytesread)
					bytesread = ft_strdup(buff);
			else
					bytesread = ft_strjoin(bytesread, buff);
				continue;
		}
		if (!bytesread)
			bytesread = ft_strdup(buff);
		else
			bytesread = ft_strjoin(bytesread, buff);
//		ft_fill(bytesread, buff);
		delnl(bytesread);
		f = 1;
	}
	free(buff);
	buff = 0;
	return (bytesread);
}
