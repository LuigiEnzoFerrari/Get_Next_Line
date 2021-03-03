#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#define BUFFER_SIZE 13

int	main(void)
{
	int fd[3];
	char buff[BUFFER_SIZE + 1];
	int bytes_read;

	fd[0] = open("a.txt", O_RDONLY);
	fd[2] = 0;
	bytes_read = read(fd[0],buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	printf("fd[0]: %s\n", buff);	
	fd[1] = open("b.txt", O_RDONLY);
	bytes_read = read(fd[1],buff, BUFFER_SIZE);
	printf("fd[1]: %s\n", buff);	
	printf("fd[0]: %d\n", fd[0]);	
	printf("fd[1]: %d\n", fd[1]);	
	close(fd[0]);
	close(fd[1]);
	return (0);
}