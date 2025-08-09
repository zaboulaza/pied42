/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:58:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/09 19:53:52 by nsmail           ###   ########.fr       */
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
	int		i;

	i = 0;
	ph = (t_philo *)arg;
	if (!arg)
		return (NULL);
	if (ph->g->ac == 6)
	{
		while (i < ph->g->eat_nb)
		{
			mini_rout(ph);
			i++;
		}
	}
	else
	{
		while (1)
			mini_rout(ph);
	}
	return (NULL);
}

int	eat(t_philo *ph)
{
	if (ph->id % 2 == 0)
		(pthread_mutex_lock(&ph->forks_l), pthread_mutex_lock(ph->forks_r));
	else
		(pthread_mutex_lock(ph->forks_r), pthread_mutex_lock(&ph->forks_l));
	ph->count++;
	if (ph->count > 1)
	{
		if (is_dead(ph) == 1)
		{
			pthread_mutex_unlock(&ph->forks_l);
			pthread_mutex_unlock(ph->forks_r);
			return (1);
		}
	}
	print(ph, "is eating");
	usleep(ph->g->t_eat * 1000);
	ph->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&ph->forks_l);
	pthread_mutex_unlock(ph->forks_r);
	return (0);
}

int	is_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->g->time);
	ph->g->time_now = get_time_in_ms();
	if (ph->g->time_now - ph->g->ph->last_meal_time > (size_t)ph->g->t_die)
	{
		print(ph, "is dead");
		pthread_mutex_unlock(&ph->g->time);
		return (1);
	}
	pthread_mutex_unlock(&ph->g->time);
	return (0);
}

int	mini_rout(t_philo *ph)
{
	pthread_mutex_lock(&ph->g->test);
	if (eat(ph) == 1)
	{
		pthread_mutex_unlock(&ph->g->test);
		exit(1);
	}
	pthread_mutex_unlock(&ph->g->test);
	if (sleep_(ph) == 1)
	{
		exit(1);
	}
	return (0);
}
