/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:08:06 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/03 20:51:26 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <sys/resource.h>

static char	*ft_strchr(const char *str, int chr)
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

static char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	return (ft_memcpy(ptr, str, len));
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	ptr[len] = '\0';
	return (ptr);
}

static int	last_returns(char **buff, char **line)
{
	char *temp;

	if (ft_strchr(*buff, '\n'))
	{
		*line = ft_substr(*buff, 0, ft_strclen(*buff, '\n'));
		if (!line)
			return (FT_ERROR);
		temp = ft_strjoin(ft_strdup(""), ft_strchr(*buff, '\n') + 1);
		free(*buff);
		*buff = temp;
		return (FT_EOL);
	}
	*line = ft_substr(*buff, 0, ft_strlen(*buff));
	if (!line)
		return (FT_ERROR);
	free(*buff);
	return (FT_EOF);
}

int			get_next_line(int fd, char **line)
{
	static char	*buff[RLIMIT_NOFILE];
	char		*buffer;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > RLIMIT_NOFILE || !line)
		return (FT_ERROR);
	if (!(buff[fd]))
		if (!(buff[fd] = ft_strdup("")))
			return (FT_ERROR);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (FT_ERROR);
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (nbytes < 0)
			return (FT_ERROR);
		buffer[nbytes] = '\0';
		buff[fd] = ft_strjoin(buff[fd], buffer);
		if (ft_strchr(buff[fd], '\n'))
			break ;
	}
	free(buffer);
	return (last_returns(&buff[fd], line));
}
