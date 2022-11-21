/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:00 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 14:30:05 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr2(const char *s, unsigned int start, size_t len)
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
	free((char *)s);
	((char *)s2)[i] = 0;
	return ((char *)s2);
}

char	*line_reader(int fd, char *line)
{
	int		b;
	char	*buff;

	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	b = read(fd, buff, BUFFER_SIZE);
	if (b == 0 && ft_strlen(line) == 0)
	{
		freee(line);
		freee(buff);
		return (0);
	}
	buff[b] = '\0';
	line = ft_strjoin(line, buff);
	while ((line && ft_strchr(line, '\n') == 0) && b == BUFFER_SIZE)
	{
		b = read(fd, buff, BUFFER_SIZE);
		buff[b] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (ft_strchr(line, '\n') == 0)
		free(buff);
	return (line);
}

char	*line_parser(char *line, int diff)
{
	int	diff2;

	diff2 = ft_strlen(ft_strchr(line, '\n'));
	line = ft_substr(line, diff + 1, diff2);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line[4086];
	int			i;
	int			diff;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (0);
	line[fd] = line_reader(fd, line[fd]);
	if (line[fd] == 0)
		return (0);
	diff = ft_strlen(line[fd]) - ft_strlen(ft_strchr(line[fd], '\n'));
	buff = ft_substr2(line[fd], 0, diff + 1);
	line[fd] = line_parser(line[fd], diff);
	return (buff);
}
