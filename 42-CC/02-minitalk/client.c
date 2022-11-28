/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/28 14:12:58 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

char	*g_msg;

static int	problemtesting(int argc, char *argv)
{
/* 	if (g_pid == 0)	{
		ft_printf("No server found\n");
		return (-1);
	} */
	argv++;
	if (argc != 3)
	{
		ft_printf("Unexpected number of arguments\n");
		return (-1);
	}
/* 	if (kill(ft_atoi(argv), SIGTERM) == -1)
	{
		ft_printf("Wrong PID\n");
		return (-1);
	} */
	return (0);
}

int	main(int argc, char **argv)
{
	if (problemtesting(argc, argv[1]) == -1)
		return (-1);
	if (ft_atoi(argv[2]) == -1)
	{
		kill(ft_atoi(argv[1]), SIGINT);
		ft_printf("Server ended");
		return (0);
	}
	return (0);
}
