/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:54:27 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/02 17:44:09 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static void	siginfohandler(int sig)
{
	if (sig == SIGIO)
	{
		return ;
	}
}

static void	charprinter(int sig, siginfo_t *siginfo, void *NUL)
{
	static unsigned char	c = 0;
	static int		i = 0;
	static pid_t		pid = 0;

	pid = siginfo->si_pid;
	(void)NUL;
	if (sig == SIGUSR1)
	{
		if (i == 0)
			c += 1;
		else
			c += (2 * i);
		kill(pid, SIGUSR1);
	}
	else
		kill(pid, SIGUSR2);
	if (i == 0)
		i++;
	else
		i *= 2;
	if (i >= 128)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	info;
	struct sigaction	s;

	ft_printf("Server PID: %d\n", getpid());
	info.sa_handler = siginfohandler;
	s.sa_sigaction = charprinter;
	s.sa_flags = SIGIO;
	sigaction(SIGIO, &info, NULL);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
