/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:30:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/04 01:33:14 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <sys/resource.h>
# include <fcntl.h>
#include <stdio.h>

# define FT_EOL			1
# define FT_EOF			0
# define FT_ERROR		-1
# define FT_LIMIT_FD	RLIMIT_NOFILE

size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t num);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strclen(const char *str, const char chr);
int		ft_strlcpy(char *dest, const char *src, size_t len);
void	ft_strdel(char **str);

#endif
