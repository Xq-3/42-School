/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 13:51:05 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	size_t		i;
	size_t		x;
	const char	*s3;

	i = -1;
	x = 0;
	if (!s1)
		size = ft_strlen(s2);
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc (sizeof(char) * (size + 1));
	if (!s3)
		return (0);
	while (s1 && s1[++i] && x < size)
		((char *)s3)[x++] = s1[i];
	i = -1;
	while (s2 && s2[++i] && x < size)
		((char *)s3)[x++] = s2[i];
	((char *)s3)[x] = '\0';
	freee((char *)s1);
	if (!(ft_strchr(s3, '\n') == 0))
		freee((char *)s2);
	return ((char *)s3);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *) str + i);
		i++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const char	*s2;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s + start))
		s2 = malloc ((sizeof(char) * (ft_strlen(s + start) + 1)));
	else
		s2 = malloc ((sizeof(char) * (len + 1)));
	if (!s2)
		return (0);
	while (s[i + start] && i < len)
	{
		((char *)s2)[i] = s[start + i];
		i++;
	}	
	((char *)s2)[i] = 0;
	return ((char *)s2);
}

void	freee(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
