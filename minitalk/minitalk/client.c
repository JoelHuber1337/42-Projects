/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:49:55 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/22 18:06:22 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

int	g_received = 0;

void	checkg(void)
{
	int	x;

	x = 0;
	while (!g_received)
	{
		sleep(1);
		x++;
		if (x == 30)
		{
			write(2, "Timeout Error\n", 14);
			exit (EXIT_FAILURE);
		}
	}
}

void	strsend(int pid, char *str, int size)
{
	int				x;
	int				bit;
	unsigned char	c;

	x = 0;
	while (x <= size)
	{
		c = str[x];
		bit = 8;
		while (bit--)
		{
			g_received = 0;
			if (c & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			checkg();
			c >>= 1;
		}
		x++;
	}
}

void	handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_received = 1;
	if (signal == SIGUSR2)
		write(1, "Message received\n", 17);
}

void	make_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int arv, char **arc)
{
	int		pid;
	int		x;
	char	*str;

	x = -1;
	if (arv == 3)
	{
		make_sigaction();
		while (arc[1][++x])
		{
			if (!(arc[1][x] >= '0' && arc[1][x] <= '9'))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
		}
		pid = ft_atoi(arc[1]);
		if (pid < 1)
			return (-1);
		str = arc[2];
		x = ft_strlen(arc[2]);
		strsend(pid, str, x);
	}
	else
		write(2, "Error\n", 6);
}
