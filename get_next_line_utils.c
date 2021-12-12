/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:15:08 by ilahyani          #+#    #+#             */
/*   Updated: 2021/12/12 22:11:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	while (i < size + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *) malloc((int) ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = (char *) malloc (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lenght;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lenght = 0;
	if (len > ft_strlen(s) - start)
		lenght = (ft_strlen(s) - start);
	else if (len <= ft_strlen(s) - start)
		lenght = len;
	sub = (char *) malloc ((lenght + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < lenght)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
