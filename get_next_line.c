#include <stdio.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define BUFFER_SIZE	10
#define FT_EOF		0
#define BANANA		666

void	*ft_memset(void *ptr, int c, size_t num)
{
	unsigned char	*str;
	unsigned char	value;

	str = ptr;
	value = (unsigned char)c;
	while (num--)
	{
		*str = value;
		str++;
	}
	return (ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
	char		*conteiner;
	static	int	read_len;

	conteiner = ft_strdup("");
	if (!buff[0])
		read_len = read(fd, buff, BUFFER_SIZE);
	while (1)
	{
		buff[read_len] = '\0';
		conteiner = ft_strjoin(conteiner, buff);
		if (ft_strchr(buff, '\n'))
		{
			*line = ft_substr(conteiner, 0, ft_strclen(conteiner, '\n'));
			break;
		}
		read_len = read(fd, buff, BUFFER_SIZE);
		if(read_len == FT_EOF)
		{
			ft_memset(buff, 0, ft_strlen(buff));
			*line = ft_substr(conteiner, 0, ft_strlen(conteiner));
			free(conteiner);
			return(0);
		}
	}

	if (read_len == FT_EOF)
	{
		printf("%dakkk\n", read_len);
		free(conteiner);
		return (0);
	}
	ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
	free(conteiner);
	return (BANANA);
}

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
