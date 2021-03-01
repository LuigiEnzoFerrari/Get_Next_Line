/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:08:06 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/28 23:40:58 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	*ft_memset(void *ptr, int c, size_t num)
{
	unsigned char	*str;
	unsigned char	value;

	str = ptr;
	value = (unsigned char)c;
	while (num--)
	{
		*str = value;
		str++;
	}
	return (ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strclen(const char *str, const char chr)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	char	c;

	c = (char)chr;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	return (ft_memcpy(ptr, str, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s) + 1;
	if (start > s_len)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, (s + start), len + 1);
	ptr[len] = 0;
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*conteiner;
	static	int	read_len;

	conteiner = ft_strdup("");
	if (!buff[0])
		read_len = read(fd, buff, BUFFER_SIZE);
	while (1)
	{
		buff[read_len] = '\0';
		conteiner = ft_strjoin(conteiner, buff);
		if (ft_strchr(buff, '\n'))
		{
			*line = ft_substr(conteiner, 0, ft_strclen(conteiner, '\n'));
			break ;
		}
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == FT_EOF)
		{
			ft_memset(buff, 0, ft_strlen(buff));
			*line = ft_substr(conteiner, 0, ft_strlen(conteiner));
			free(conteiner);
			return (0);
		}
	}
	if (read_len == FT_EOF)
	{
		free(conteiner);
		return (0);
	}
	ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
	free(conteiner);
	return (BANANA);
}
