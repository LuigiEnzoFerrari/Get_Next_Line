#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE	1000
#endif

int		get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	size_t read_len;

	read_len = read(fd, buff, BUFFER_SIZE);
	buff[read_len] = '\0';
	*line = buff;
	return (read_len);
}

int main (void) 
{ 
	char	*line;
	int		fd;
	size_t	num;

	fd = open("a.txt", O_RDONLY);//O_RDWR


	num = get_next_line(fd, &line);

	printf("%s\n", line);
	printf("%ld\n", num);
	return (0);
}

