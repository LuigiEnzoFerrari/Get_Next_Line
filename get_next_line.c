/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:08:06 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/16 03:37:16 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	last_returns(int n, char **buff, char **line)
{
	char	*temp;

	if (n < 0)
		return (FT_ERROR);
	*line = ft_substr(*buff, 0, ft_strclen(*buff, '\n'));
	if (!line)
		return (FT_ERROR);
	if (ft_strchr(*buff, '\n'))
	{
		temp = ft_strdup(ft_strchr(*buff, '\n') + 1);
		ft_strdel(&*buff);
		*buff = temp;
		return (FT_EOL);
	}
	ft_strdel(&*buff);
	return (FT_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff[RLIMIT_NOFILE];
	char		*buffer;
	int			nbytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > RLIMIT_NOFILE || !line)
		return (FT_ERROR);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	if (!buff[fd])
		return (FT_ERROR);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (FT_ERROR);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		buff[fd] = ft_rejoin(buff[fd], buffer);
		if (ft_strchr(buff[fd], '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	ft_strdel(&buffer);
	return (last_returns(nbytes, &buff[fd], line));
}
