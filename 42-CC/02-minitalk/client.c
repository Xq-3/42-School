/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/02 17:31:16 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static int	problemtesting(int argc, int pid, char *argv)
{
	if (argc != 3)
	{
		ft_printf("Unexpected number of arguments\n");
		return (-1);
	}
	if (ft_strlen(argv) == 0)
	{
		ft_printf("Invalid sentence\n");
		return (-1);
	}
	if (kill(pid, SIGINFO) != 0)
	{
		ft_printf("Wrong pid\n");
		return (-1);
	}
	return (0);
}

static void	charsender(int pid, char argv)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(300);
		if ((argv & 1))
			kill(pid, SIGUSR1);
		if (!(argv & 1))
			kill(pid, SIGUSR2);
		argv = argv >> 1;
	}
	usleep(300);
}

int	main(int argc, char **argv)
{
	int			i;

	i = 0;
	if (problemtesting(argc, ft_atoi(argv[1]), argv[2]) == -1)
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
	usleep(100);
	charsender(ft_atoi(argv[1]), '\n');
	return (0);
}
