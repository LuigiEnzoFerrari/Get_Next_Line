/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:42:38 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/01 13:42:03 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
# include <fcntl.h> 

int main (void) 
{
	char	*line;
	int		fd;
	int		get_next;
	int		i;

	i = 0;
	get_next = 1;
	fd = open("a.txt", O_RDONLY);//O_RDWR
	while (get_next > FT_EOF)
	{
		get_next = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
