/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:34:09 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/03 12:53:30 by lenzo-pe         ###   ########.fr       */
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
	int		get_next1;
	int		get_next2;
	int		i;

	i = 0;
	get_next1 = 1;
	get_next2 = 1;
	fd[0] = open("a.txt", O_RDONLY);
	fd[1] = open("b.txt", O_RDONLY);
	// while (get_next1 > FT_EOF)
	// {
	// 	get_next1 = get_next_line(fd[0], &line);
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	// printf("ola\n\n");
	// while (get_next2 > FT_EOF)
	// {
	// 	get_next2 = get_next_line(fd[1], &line);
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	
	while (get_next2 > FT_EOF && get_next1 >FT_EOF)
	{
		get_next1 = get_next_line(fd[0], &line);
		printf("%s\n", line);
		free(line);

		get_next2 = get_next_line(fd[1], &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
