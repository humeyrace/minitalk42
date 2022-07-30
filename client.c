/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acengiz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:26:37 by acengiz           #+#    #+#             */
/*   Updated: 2022/07/27 17:00:42 by acengiz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"
#include <signal.h>
#include <stdio.h>

void	getbit(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str >> i & 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int arg, char **argv)
{
	int	pid;

	if (arg == 3)
	{
		pid = ft_atoi(argv[1]);
		getbit(pid, argv[2]);
	}
	return (0);
}
