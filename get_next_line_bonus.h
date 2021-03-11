/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:22:10 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/04 15:48:01 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t num);
size_t	ft_strlen(const char *str);
size_t	ft_strclen(const char *str, const char chr);
void	ft_strdel(char **str);

#endif
