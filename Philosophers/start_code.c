/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:58:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/02 05:09:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	start_code(t_general *g)
{
	init_fork(g);
	creat_thread(g);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;

	if (!arg)
		return (NULL);
	ph = (t_philo *)arg;
	rout_eat(ph);
	rout_sleep(ph);
	return (NULL);
}

void	eat(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_lock(&ph->forks_l);
		pthread_mutex_lock(ph->forks_r);
	}
	else
	{
		pthread_mutex_lock(ph->forks_r);
		pthread_mutex_lock(&ph->forks_l);
	}
	rout_printf(ph, "is eating");
	usleep(ph->g->t_eat);
	ph->g->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&ph->forks_l);
	pthread_mutex_unlock(ph->forks_r);
}

void	print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->g->print);
	size_t timestamp = ph->g->last_meal_time - ph->g->start_time;
	printf("%zu philo[%d] %s\n",timestamp, ph->id, str);
	pthread_mutex_unlock(&ph->g->print);
}

void	sleep(t_philo *ph)
{
	rout_printf(ph, "is sleeping");
	usleep(ph->g->t_sleep);
}

void is_dead(ph)
{
	gettimeofday(&ph->g->start_time, NULL);
	if time_to_die <  + time_to_sleep
		is_dead 
}

// lock les forks
// mange donc usleep
// unlock
// dors donc usleep
// think