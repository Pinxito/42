/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:38:32 by gguillen          #+#    #+#             */
/*   Updated: 2025/10/30 14:26:36 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int	check_params(t_shared *s)
{
	if (s->philos_count < 1 || s->philos_count > 200)
		return (1);
	if (s->time_die <= 0 || s->time_eat <= 0 || s->time_sleep <= 0)
		return (1);
	if (s->required_meals == 0)
		return (1);
	return (0);
}

int	validate_and_set_params(t_shared *s, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			return (printf(MSG_SYNTAX), 1);
		i++;
	}
	s->philos_count = (int)str_to_long(argv[1]);
	s->time_die = str_to_long(argv[2]);
	s->time_eat = str_to_long(argv[3]);
	s->time_sleep = str_to_long(argv[4]);
	s->required_meals = -1;
	if (argv[5])
		s->required_meals = (int)str_to_long(argv[5]);
	if (check_params(s))
		return (printf(MSG_DATA), 1);
	return (0);
}

int	init_shared(t_shared *s, char **argv)
{
	s->someone_dead = 0;
	s->all_finished = 0;
	if (validate_and_set_params(s, argv))
		return (1);
	s->forks = malloc(sizeof(pthread_mutex_t) * s->philos_count);
	if (!s->forks)
		return (printf(MSG_MEM), 1);
	if (pthread_mutex_init(&s->print_lock, NULL) != 0
		|| pthread_mutex_init(&s->state_lock, NULL) != 0
		|| pthread_mutex_init(&s->meal_lock, NULL) != 0)
		return (printf(MSG_MUTEX), 1);
	return (0);
}

int	init_philos(t_shared *s)
{
	int	i;

	s->list = malloc(sizeof(t_philosopher) * s->philos_count);
	if (!s->list)
		return (printf(MSG_MEM), 1);
	i = -1;
	while (++i < s->philos_count)
	{
		if (pthread_mutex_init(&s->forks[i], NULL) != 0)
			return (printf(MSG_MUTEX), 1);
		s->list[i].shared = s;
		s->list[i].id = i + 1;
		s->list[i].meals = 0;
		s->list[i].right_fork = i;
		s->list[i].left_fork = (i + 1) % s->philos_count;
		s->list[i].last_meal_ms = 0;
	}
	return (0);
}
