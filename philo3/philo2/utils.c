/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:47:30 by gguillen          #+#    #+#             */
/*   Updated: 2025/10/30 03:02:00 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	smart_sleep(long duration_ms, t_shared *s)
{
	long	start;
	long	elapsed;

	start = current_time_ms();
	while (!is_someone_dead(s) && !is_all_finished(s))
	{
		elapsed = current_time_ms() - start;
		if (elapsed >= duration_ms)
			break ;
		if (duration_ms - elapsed > 5)
			usleep(1000);
		else
			usleep(100);
	}
}

long	str_to_long(const char *s)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	is_numeric(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
