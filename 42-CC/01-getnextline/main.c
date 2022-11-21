/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:50:37 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/21 17:43:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
 //-fsanitize=address -g 
int	main(void)
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open("/Users/pfaria-d/francinette/tests/get_next_line/fsoares/one_line_no_nl.txt", O_RDONLY);
	while (i < 10000)
	{
		line = get_next_line(0);
		printf("%s", line);
		i++;
	}
	return (0);
}
