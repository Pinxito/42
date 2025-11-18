/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:36:52 by gguillen          #+#    #+#             */
/*   Updated: 2025/11/17 16:20:01 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <math.h>

# define MSG_USAGE "\nUsage: ./philo \
<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[<number_of_meals>]\n\n"
# define MSG_SYNTAX "\nSyntax error: only positive integers allowed\n\n"
# define MSG_DATA "\nData error: philosophers 1..200, all times > 0\n\n"
# define MSG_MEM "\nMemory allocation error\n\n"
# define MSG_MUTEX "\nMutex init/destroy error\n\n"
# define MSG_THREAD "\nThread create/join error\n\n"

typedef struct s_philosopher	t_philosopher;

typedef struct s_shared
{
	int							philos_count;
	long						time_die;
	long						time_eat;
	long						time_sleep;
	int							required_meals;
	long						start_ms;
	int							someone_dead;
	int							all_finished;
	t_philosopher				*list;
	pthread_mutex_t				*forks;
	pthread_mutex_t				print_lock;
	pthread_mutex_t				state_lock;
	pthread_mutex_t				meal_lock;
}								t_shared;

typedef struct s_philosopher
{
	pthread_t					thread;
	t_shared					*shared;
	int							id;
	int							right_fork;
	int							left_fork;
	int							meals;
	long						last_meal_ms;
}								t_philosopher;

/* setup & parsing */
int								init_shared(t_shared *s, char **argv);
int								init_philos(t_shared *s);
int								validate_and_set_params(t_shared *s,
									char **argv);

/* simulation */
int								start_simulation(t_shared *s);
void							*philo_routine(void *arg);
void							one_philo_case(t_shared *s, t_philosopher *ph);

/* actions & display */
void							show_event(t_shared *s, t_philosopher *ph,
									char code);
void							perform_eat(t_shared *s, t_philosopher *ph);

/* monitor & end */
void							monitor_loop(t_shared *s);
int								check_all_meals(t_shared *s);
void							mark_death(t_shared *s, t_philosopher *ph);
void							mark_finished(t_shared *s);

/* utils */
long							current_time_ms(void);
void							smart_sleep(long duration_ms, t_shared *s);
long							str_to_long(const char *s);
int								is_numeric(const char *s);
/* state access (thread-safe) */
int								is_someone_dead(t_shared *s);
int								is_all_finished(t_shared *s);
void							set_someone_dead(t_shared *s, int v);
void							set_all_finished(t_shared *s, int v);

#endif
