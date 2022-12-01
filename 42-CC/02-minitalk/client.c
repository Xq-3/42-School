/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/01 16:49:18 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static int	problemtesting(int argc, char *argv)
{
	argv++;
	if (argc != 3)
	{
		ft_printf("Unexpected number of arguments\n");
		return (-1);
	}
/* 	if (kill(ft_atoi(argv), SIGUSR1) != 0)
	{
		ft_printf("Wrong pid");
		return (-1);
	} */
	return (0);
}

void	charsender(int pid, char argv)
{
	int	i;
	int	x;

	x = 0;
	i = 8;
	while (i--)
	{
		if ((argv & 1) == 1)
			kill(pid, SIGUSR1);
		if ((argv & 1) == 0)
			kill(pid, SIGUSR2);
		usleep(50);
		argv = argv >> 1;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (problemtesting(argc, argv[1]) == -1)
		return (-1);
	if (ft_atoi(argv[2]) == -1)
	{
		kill(ft_atoi(argv[1]), SIGINT);
		return (0);
	}
	while (argv[2][i])
	{
		charsender(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
