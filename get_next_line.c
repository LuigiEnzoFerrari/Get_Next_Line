#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE	25
#define BANANA		666

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
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	static char	*conteiner;
	size_t	read_len;
	size_t	i;

	if (!conteiner)
		conteiner = ft_strdup("");
	while ((read_len = read(fd, buff, BUFFER_SIZE) > 0))
	{
		temp = ft_strjoin(conteiner, buff);
		free(conteiner);
		conteiner = temp;
		if (ft_strchr(temp, '\n'))
		{
			*line = ft_substr(temp, 0, ft_strclen(temp, '\n'));
			break;
		}
		i++;
	}
	
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
	printf("%s\n", line);
	return (0);
}
