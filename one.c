/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:34:09 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/03 00:55:58 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd[3];
	int		get_next;
	int		i;

	i = 0;
	get_next = 1;
	fd[0] = open("a.txt", O_RDONLY);
	while (get_next > FT_EOF)
	{
		get_next = get_next_line(fd[0], &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd[0]);
	fd[1] = open("b.txt", O_RDONLY);
	while (get_next > FT_EOF)
	{
		get_next = get_next_line(fd[1], &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd[1]);
	return (0);
}
