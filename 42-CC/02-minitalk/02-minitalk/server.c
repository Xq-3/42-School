/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/07 12:57:55 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static void	siginfohandler(int sig)
{
	if (sig == SIGINFO)
	{
		return ;
	}
}

static void	charprinter(int sig, siginfo_t *siginfo, void *NUL)
{
	static int				c = 0;
	static int				i = 1;
	static pid_t			pid = 0;

	(void)NUL;
	pid = siginfo->si_pid;
	if (sig == SIGUSR1)
		c += 256;
	c = c >> 1;
	if (++i >= 9)
	{
		i = ft_printf("%c", c);
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	info;
	struct sigaction	s;

	ft_printf("Server PID: %d\n", getpid());
	info.sa_handler = siginfohandler;
	s.sa_sigaction = charprinter;
	sigaction(SIGINFO, &info, NULL);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
	{
	}
	return (0);
}
