/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:08:06 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/02 23:41:58 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <sys/resource.h>

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

	static char	*buff[RLIMIT_NOFILE];
	char	*buffer;
	int		nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > RLIMIT_NOFILE)
		return (FT_ERROR);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
		if (!buff[fd])
			return (FT_ERROR);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (nbytes < 0)
			return(FT_ERROR);
		buffer[nbytes] = '\0';
		buff[fd] = ft_strjoin(buff[fd], buffer);
		if (ft_strchr(buff[fd], '\n'))
		{
			*line = ft_substr(buff[fd], 0, ft_strclen(buff[fd], '\n'));
				if (!line)
					return (FT_ERROR);
			buff[fd] = ft_strjoin(ft_strdup(""), ft_strchr(buff[fd], '\n') + 1);
			return (FT_EOL);
		}
	}
	*line = ft_substr(buff[fd], 0, ft_strlen(buff[fd]));
	if (!line)
		return (FT_ERROR);
	free(buffer);
	return(FT_EOF);
}


int main (void) 
{
	char	*line;
	int		fd;
	int		get_next;
	int		i;
	
	i = 0;
	get_next = 1;
	fd = open("a.txt", O_RDONLY);//O_RDWR
	while (get_next > 0)
	{
		get_next = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
