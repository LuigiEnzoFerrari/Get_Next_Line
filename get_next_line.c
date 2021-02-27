#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define BUFFER_SIZE	5000
#define BANANA		666

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char    *ft_strnew(size_t size)
{
    char    *str;

    if (!(str = (char *)malloc(sizeof(char) * size + 1)))
        return (NULL);
    str[size] = '\0';
    while (size--)
        str[size] = '\0';
    return (str);
}

size_t	ft_strclen(const char *str, const char chr)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int chr)
{
	char	c;

	c = (char)chr;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	return (ft_memcpy(ptr, str, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s) + 1;
	if (start > s_len)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, (s + start), len + 1);
	ptr[len] = 0;
	return (ptr);
}


int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*temp;
	char	*conteiner;
	int		read_len;

	conteiner = ft_strnew(1);
	//printf(">:%s:< \n", buff);
	if (!buff[0])
		read_len = read(fd, buff, BUFFER_SIZE);
	while (read_len > 0)
	{
		buff[read_len] = '\0';
		temp = ft_strjoin(conteiner, buff);
		free(conteiner);
		conteiner = temp;
		if (ft_strchr(buff, '\n'))
		{
			*line = ft_substr(conteiner, 0, ft_strclen(conteiner, '\n'));
			break;
		}
		read_len = read(fd, buff, BUFFER_SIZE);

	}
	free(temp);
	ft_strncpy(buff, ft_strchr(buff, '\n') + 1, read_len);
	if (!read_len)
		return (0);
	return (BANANA);
}







int main (void) 
{ 
	char	*line;
	int		fd;

	fd = open("a.txt", O_RDONLY);//O_RDWR

	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);

	close(fd);
	return (0);
}
