/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:28:52 by gguillen          #+#    #+#             */
/*   Updated: 2025/11/17 16:17:05 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	perform_eat(t_shared *s, t_philosopher *ph)
{
	if (ph->id % 2 == 1)
	{
		pthread_mutex_lock(&s->forks[ph->right_fork]);
		show_event(s, ph, 'F');
		pthread_mutex_lock(&s->forks[ph->left_fork]);
		show_event(s, ph, 'F');
	}
	else
	{
		pthread_mutex_lock(&s->forks[ph->left_fork]);
		show_event(s, ph, 'F');
		pthread_mutex_lock(&s->forks[ph->right_fork]);
		show_event(s, ph, 'F');
	}
	pthread_mutex_lock(&s->meal_lock);
	ph->last_meal_ms = current_time_ms();
	ph->meals++;
	pthread_mutex_unlock(&s->meal_lock);
	show_event(s, ph, 'E');
	smart_sleep(s->time_eat, s);
	pthread_mutex_unlock(&s->forks[ph->left_fork]);
	pthread_mutex_unlock(&s->forks[ph->right_fork]);
}

int	is_someone_dead(t_shared *s)
{
	int	v;

	pthread_mutex_lock(&s->state_lock);
	v = s->someone_dead;
	pthread_mutex_unlock(&s->state_lock);
	return (v);
}

int	is_all_finished(t_shared *s)
{
	int	v;

	pthread_mutex_lock(&s->state_lock);
	v = s->all_finished;
	pthread_mutex_unlock(&s->state_lock);
	return (v);
}

void	set_someone_dead(t_shared *s, int v)
{
	pthread_mutex_lock(&s->state_lock);
	s->someone_dead = v;
	pthread_mutex_unlock(&s->state_lock);
}
