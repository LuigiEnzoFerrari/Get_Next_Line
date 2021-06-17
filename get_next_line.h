/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:30:57 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/06/16 03:32:45 by lenzo-pe         ###   ########.fr       */
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
# include "libft.h"

# define FT_EOL			1
# define FT_EOF			0
# define FT_ERROR		-1
# define FT_LIMIT_FD	RLIMIT_NOFILE
# define BUFFER_SIZE	40

int		get_next_line(int fd, char **line);

#endif
