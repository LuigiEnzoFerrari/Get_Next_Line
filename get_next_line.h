/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:30:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/02/28 23:44:09 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include "get_next_line.h"

# define BUFFER_SIZE	1
# define FT_EOF			0
# define BANANA			666

int		get_next_line(int fd, char **line);
void	*ft_memcpy(void *dest, const void *src, size_t num);
size_t	ft_strlen(const char *str);
int		ft_strlcpy(char *dest, const char *src, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
