/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acengiz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:27:18 by acengiz           #+#    #+#             */
/*   Updated: 2022/07/27 17:00:06 by acengiz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd (num / 10, fd);
	ft_putchar_fd (num % 10 + '0', fd);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
		number = (10 * number) + (*str++ - 48);
	return ((number) * sign);
}
