/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:33:58 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/04 13:17:35 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *str, const char chr)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dest && !src)
		return (dest);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (num--)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	return (dest);
}

int		ft_strlcpy(char *dest, const char *src, size_t len)
{
	unsigned int	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (len == 0)
		return (src_len);
	if (src_len >= len)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
		return (src_len);
	}
	ft_memcpy(dest, src, src_len);
	dest[src_len] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (size + src_len);
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1) + 1;
	s2_len = ft_strlen(s2);
	total_len = s2_len + s1_len;
	ptr = (char *)malloc(sizeof(char) * (total_len));
	if (!ptr)
	{
		ft_strdel(&s1);
		return (0);	
	}
	ft_strlcpy(ptr, s1, s1_len);
	ft_strlcat(ptr, s2, total_len);
	ft_strdel(&s1);
	return (ptr);
}
