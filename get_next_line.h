/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:30:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/05/07 18:21:13 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <fcntl.h>

# define FT_EOL			1
# define FT_EOF			0
# define FT_ERROR		-1
# define FT_LIMIT_FD	RLIMIT_NOFILE
# define BUFFER_SIZE	3

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dest, const void *src, size_t num);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strclen(const char *str, const char chr);
void	ft_strdel(char **str);

#endif
