/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:58:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/16 23:49:27 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	start_code(t_general *g)
{
	init_fork(g);
	if (creat_thread(g) == 1)
		return (1);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)arg;
	if (!ph)
		return (NULL);
	if (ph->g->nb_philo == 1)
	{
		print(ph, "has taken a fork");
		usleep(ph->g->t_die * 1000);
		print(ph, "is dead");
		return (NULL);
	}
	if (ph->id % 2 == 1)
		usleep(1000);
	i = 0;
	if (ph->g->ac == 6)
	{
		while (i < ph->g->eat_nb)
		{
			if (i == ph->g->eat_nb)
			{
				pthread_mutex_lock(&ph->g->time);
				ph->g->compt = 1;
				pthread_mutex_unlock(&ph->g->time);
				break ;
			}
			if (mini_rout(ph) == 1)
				break ;
			i++;
		}
	}
	else
	{
		while (is_philo_dead(ph->g) == 0)
		{
			if (mini_rout(ph) == 1)
				break ;
		}
	}
	return (NULL);
}

int	eat(t_philo *ph)
{
	size_t	start;
	size_t	now;

	if (is_philo_dead(ph->g) == 1 || is_dead(ph) == 1)
		return (1);
	if (ph->id % 2 == 0)
		(pthread_mutex_lock(&ph->forks_l), pthread_mutex_lock(ph->forks_r));
	else
		(pthread_mutex_lock(ph->forks_r), pthread_mutex_lock(&ph->forks_l));
	if (is_dead(ph) == 1 || is_philo_dead(ph->g) == 1)
	{
		(pthread_mutex_unlock(&ph->forks_l), pthread_mutex_unlock(ph->forks_r));
		return (1);
	}
	start = get_time_in_ms();
	print(ph, "has taken a fork");
	print(ph, "has taken a fork");
	print(ph, "is eating");
	pthread_mutex_lock(&ph->last_meal_mutex);
	ph->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&ph->last_meal_mutex);
	while (1)
	{
		if (is_dead(ph) == 1 || is_philo_dead(ph->g) == 1
			|| check_usleep(ph->g) == 1)
		{
			(pthread_mutex_unlock(&ph->forks_l),
				pthread_mutex_unlock(ph->forks_r));
			return (1);
		}
		now = get_time_in_ms();
		if (now - start >= (size_t)ph->g->t_eat)
			break ;
		usleep(500);
	}
	if (is_dead(ph) == 1 || is_philo_dead(ph->g) == 1)
	{
		pthread_mutex_unlock(&ph->forks_l);
		pthread_mutex_unlock(ph->forks_r);
		return (1);
	}
	pthread_mutex_unlock(&ph->forks_l);
	pthread_mutex_unlock(ph->forks_r);
	return (0);
}

int	is_dead(t_philo *ph)
{
	size_t	last_meal;

	pthread_mutex_lock(&ph->g->time);
	ph->g->time_now = get_time_in_ms();
	pthread_mutex_lock(&ph->last_meal_mutex);
	last_meal = ph->last_meal_time;
	pthread_mutex_unlock(&ph->last_meal_mutex);
	if (ph->g->time_now - last_meal > (size_t)ph->g->t_die)
	{
		if (ph->g->all_ready_print != 1)
		{
			print(ph, "is dead");
			// pthread_mutex_lock(&ph->g->dead_mut);
			ph->g->all_ready_print = 1;
			// pthread_mutex_unlock(&ph->g->dead_mut);
		}
		pthread_mutex_lock(&ph->g->dead_mut);
		ph->g->dead = 1;
		pthread_mutex_unlock(&ph->g->dead_mut);
		pthread_mutex_unlock(&ph->g->time);
		return (1);
	}
	pthread_mutex_unlock(&ph->g->time);
	return (0);
}

int	mini_rout(t_philo *ph)
{
	if (is_philo_dead(ph->g) == 1)
		return (1);
	if (eat(ph) == 1)
		return (1);
	if (sleep_(ph) == 1)
		return (1);
	return (0);
}

//  ./Philosophers 5 800 200 200 7 verif ce tes