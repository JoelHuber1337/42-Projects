/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuber <jhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:03 by jhuber            #+#    #+#             */
/*   Updated: 2024/02/21 17:46:04 by jhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

int	g_x = 0;

void	charterm(siginfo_t *info, char **str)
{
	kill(info->si_pid, SIGUSR2);
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
	return ;
}

void	print_signal(siginfo_t *info, char c)
{
	static char	*tmp;
	static char	*str;

	if (str == NULL)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return ;
		str[0] = '\0';
	}
	if (c == '\0')
		charterm(info, &str);
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (tmp == NULL)
			return ;
		tmp[0] = c;
		tmp[1] = '\0';
		str = ft_strjoin(str, tmp);
		free (tmp);
		if (str == NULL)
			return ;
	}
}

void	decode_signal(int signum, siginfo_t *info, void *context)
{
	static int		bits;
	static char		c;

	if (g_x == 0)
	{
		c = 0;
		bits = 0;
		g_x++;
	}
	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << bits);
	if (bits == 7)
	{
		print_signal(info, c);
		g_x = 0;
	}
	bits++;
	kill(info->si_pid, SIGUSR1);
}

void	make_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &decode_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID =>%d\n", pid);
	make_sigaction();
	while (42)
		pause();
}
