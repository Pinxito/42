/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:21:36 by gguillen          #+#    #+#             */
/*   Updated: 2025/11/17 16:16:40 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cleanup_all(t_shared *s)
{
	int	i;

	i = -1;
	while (++i < s->philos_count)
	{
		pthread_mutex_destroy(&s->forks[i]);
	}
	pthread_mutex_destroy(&s->print_lock);
	pthread_mutex_destroy(&s->state_lock);
	pthread_mutex_destroy(&s->meal_lock);
	free(s->forks);
	free(s->list);
	return (0);
}

static int	create_philosophers(t_shared *s)
{
	int	i;
	int	created;

	created = 0;
	i = -1;
	while (++i < s->philos_count)
	{
		if (pthread_create(&s->list[i].thread, NULL, philo_routine,
				&s->list[i]) != 0)
		{
			printf(MSG_THREAD);
			set_someone_dead(s, 1);
			while (created > 0)
			{
				created--;
				pthread_join(s->list[created].thread, NULL);
			}
			cleanup_all(s);
			return (1);
		}
		created++;
	}
	return (0);
}

int	start_simulation(t_shared *s)
{
	int	i;

	s->start_ms = current_time_ms();
	i = -1;
	while (++i < s->philos_count)
		s->list[i].last_meal_ms = s->start_ms;
	if (create_philosophers(s))
		return (1);
	if (s->philos_count > 1)
		monitor_loop(s);
	i = -1;
	while (++i < s->philos_count)
		pthread_join(s->list[i].thread, NULL);
	cleanup_all(s);
	return (0);
}

void	one_philo_case(t_shared *s, t_philosopher *ph)
{
	pthread_mutex_lock(&s->forks[ph->right_fork]);
	show_event(s, ph, 'F');
	pthread_mutex_unlock(&s->forks[ph->right_fork]);
	smart_sleep(s->time_die, s);
	show_event(s, ph, 'D');
}

void	*philo_routine(void *arg)
{
	t_philosopher	*ph;
	t_shared		*s;

	ph = (t_philosopher *)arg;
	s = ph->shared;
	if (s->philos_count == 1)
	{
		one_philo_case(s, ph);
		return (NULL);
	}
	while (!is_someone_dead(s) && !is_all_finished(s))
	{
		perform_eat(s, ph);
		if (is_someone_dead(s) || is_all_finished(s))
			break ;
		show_event(s, ph, 'S');
		smart_sleep(s->time_sleep, s);
		show_event(s, ph, 'T');
	}
	return (NULL);
}
