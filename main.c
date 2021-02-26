#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define	BUFF	9
int main (void) 
{ 
    int fd[2]; 
    char buf2[BUFF]; 
  
    fd[1] = open("a.txt", O_RDWR);

    write(1, buf2, read(fd[1], buf2, BUFF)); 
  
    close(fd[1]); 
  
    return 0; 
}
