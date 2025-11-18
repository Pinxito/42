/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitorhelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:55 by gguillen          #+#    #+#             */
/*   Updated: 2025/11/17 16:18:03 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mark_death(t_shared *s, t_philosopher *ph)
{
	pthread_mutex_lock(&s->state_lock);
	if (!s->someone_dead)
	{
		s->someone_dead = 1;
		pthread_mutex_unlock(&s->state_lock);
		show_event(s, ph, 'D');
	}
	else
	{
		pthread_mutex_unlock(&s->state_lock);
	}
}

void	mark_finished(t_shared *s)
{
	if (!is_all_finished(s))
		set_all_finished(s, 1);
}

static void	check_meals_completion(t_shared *s)
{
	int	i;
	int	finished_count;

	finished_count = 0;
	i = 0;
	while (i < s->philos_count)
	{
		pthread_mutex_lock(&s->meal_lock);
		if (s->list[i].meals >= s->required_meals)
			finished_count++;
		pthread_mutex_unlock(&s->meal_lock);
		i++;
	}
	if (finished_count == s->philos_count)
		mark_finished(s);
}

void	monitor_loop(t_shared *s)
{
	int		i;
	long	now;
	long	diff;

	while (!is_all_finished(s))
	{
		i = 0;
		now = current_time_ms();
		while (i < s->philos_count && !is_someone_dead(s))
		{
			pthread_mutex_lock(&s->meal_lock);
			diff = now - s->list[i].last_meal_ms;
			if (diff > s->time_die)
				mark_death(s, &s->list[i]);
			pthread_mutex_unlock(&s->meal_lock);
			i++;
		}
		if (is_someone_dead(s))
			break ;
		if (s->required_meals != -1)
			check_meals_completion(s);
	}
}

void	set_all_finished(t_shared *s, int v)
{
	pthread_mutex_lock(&s->state_lock);
	s->all_finished = v;
	pthread_mutex_unlock(&s->state_lock);
}
