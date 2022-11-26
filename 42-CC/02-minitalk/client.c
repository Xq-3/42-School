/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:24 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/26 11:24:46 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

char	*g_msg;

static int	problemtesting(int argc, char *argv)
{
	if (g_pid == 0)
	{
		ft_printf("No server found\n");
		return (-1);
	}
	if (argc != 3)
	{
		ft_printf("Unexpected number of arguments\n");
		return (-1);
	}
	if (g_pid != ft_atoi(argv))
	{
		ft_printf("Wrong PID\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (problemtesting(argc, argv[1]) == -1)
		return (-1);
	g_msg = argv[2];
	return (0);
}
