/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:37:47 by gguillen          #+#    #+#             */
/*   Updated: 2025/10/30 13:50:11 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	should_print_event(t_shared *s, char code)
{
	int	dead;
	int	finished;

	pthread_mutex_lock(&s->state_lock);
	dead = s->someone_dead;
	finished = s->all_finished;
	pthread_mutex_unlock(&s->state_lock);
	if ((dead || finished) && code != 'D')
		return (0);
	return (1);
}

void	show_event(t_shared *s, t_philosopher *ph, char code)
{
	long	time;

	if (!should_print_event(s, code))
		return ;
	pthread_mutex_lock(&s->print_lock);
	time = current_time_ms() - s->start_ms;
	if (code == 'F')
		printf("%ld %d has taken a fork\n", time, ph->id);
	else if (code == 'E')
		printf("%ld %d is eating\n", time, ph->id);
	else if (code == 'S')
		printf("%ld %d is sleeping\n", time, ph->id);
	else if (code == 'T')
		printf("%ld %d is thinking\n", time, ph->id);
	else if (code == 'D')
	{
		printf("%ld %d died\n", time, ph->id);
		set_someone_dead(s, 1);
	}
	pthread_mutex_unlock(&s->print_lock);
}

int	main(int argc, char **argv)
{
	t_shared	data;

	if (argc != 5 && argc != 6)
		return (printf(MSG_USAGE), 1);
	if (init_shared(&data, argv))
		return (1);
	if (init_philos(&data))
		return (1);
	if (start_simulation(&data))
		return (1);
	return (0);
}
