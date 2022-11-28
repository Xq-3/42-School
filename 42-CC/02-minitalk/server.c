/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/28 13:44:14 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int	server(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

int	main(void)
{
	server();
	return (0);
}
