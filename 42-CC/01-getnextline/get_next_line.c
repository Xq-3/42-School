/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:00 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:49 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (ft_strlen(line) == 0)
		freee(line);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	int			i;
	int			diff;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (0);
	line = line_reader(fd, line);
	if (line == 0)
		return (0);
	diff = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n'));
	printf("%p\n", line);
	buff = ft_substr(line, 0, diff + 1);
	printf("%p\n", line);
	line = line_parser(line, diff);
	return (buff);
}
