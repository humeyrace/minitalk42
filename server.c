/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acengiz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:26:47 by acengiz           #+#    #+#             */
/*   Updated: 2022/07/27 12:43:13 by acengiz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"
#include <signal.h>

void	send_signal(int sig)
{
	static unsigned char	x;
	static int				i;

	if (sig == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		ft_putchar_fd(x, 1);
		x = 0;
		i = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd (getpid(), 1);
	ft_putchar_fd ('\n', 1);
	signal (SIGUSR1, send_signal);
	signal (SIGUSR2, send_signal);
	while (42)
		pause();
	return (0);
}
