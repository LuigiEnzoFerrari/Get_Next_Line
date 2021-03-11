/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:22:17 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/03/04 15:44:48 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc((s1_len + s2_len + 1) * sizeof(*ptr));
	if (!ptr)
	{
		ft_strdel(&s1);
		return (NULL);
	}
	while (s1[++i])
		ptr[i] = s1[i];
	i = -1;
	while (s2[++i])
		ptr[s1_len++] = s2[i];
	ptr[s1_len] = '\0';
	ft_strdel(&s1);
	return (ptr);
}
