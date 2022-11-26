/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/26 11:25:51 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int	g_pid;

int	server(void)
{
	g_pid = getpid();
	ft_printf("Server PID: %d\n", g_pid);
	while (1)
	{
		ft_printf("%s\n", g_msg);
		usleep(100000);
	}
	return (0);
}

int	main(void)
{
	server();
	return (0);
}
