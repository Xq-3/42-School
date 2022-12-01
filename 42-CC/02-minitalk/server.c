/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/01 16:54:13 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int	server(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		usleep(500);
	}
	return (0);
}

void	test(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("1");
	if (sig == SIGUSR2)
		ft_printf("0");
}

char	charprinter(void)
{
	int				i;
	int				x;
	unsigned char	c;
	int				z;

	x = 0;
	i = 8;
	z = 256;
	c = 0;
	while (i--)
	{
		if (signal(SIGUSR1, test))
			c += (2 * x);
		if (signal(SIGUSR2, test))
			c = c - 1 + 1;
		if (x == 0)
			x++;
		else
			x *= 2;
		usleep(5000);
		z /= 2;
	}
	return (c);
}

int	main(void)
{
	server();
	return (0);
}
