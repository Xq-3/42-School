/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/07 12:53:45 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

size_t	g_len;

static void	charcounter(int sig)
{
	static size_t	count = 0;

	if (sig == SIGUSR1)
		count++;
	if (count == (g_len * 8) + 8)
		ft_printf("Received");
}

static void	charsender(int pid, char *argv)
{
	int	i;
	int	x;
	int	tmp;

	x = 0;
	while (argv[x])
	{
		tmp = argv[x];
		i = 8;
		while (i--)
		{
			usleep(400);
			if ((tmp & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			tmp = tmp >> 1;
			usleep(400);
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Unexpected number of arguments\n");
		return (-1);
	}	
	if (ft_atoi(argv[1]) == 0 || kill(ft_atoi(argv[1]), SIGINFO) != 0)
	{
		ft_printf("Wrong pid\n");
		return (-1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("Invalid sentence\n");
		return (-1);
	}
	g_len = ft_strlen(argv[2]);
	signal(SIGUSR1, charcounter);
	charsender(ft_atoi(argv[1]), argv[2]);
	charsender(ft_atoi(argv[1]), "\n");
	return (0);
}
