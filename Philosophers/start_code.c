/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:58:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/13 07:18:31 by nsmail           ###   ########.fr       */
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
	if (ph->g->nb_philo == 1)
	{
		print(ph, "is dead");
		return (NULL);
	}
	if (ph->id % 2 == 1)
		usleep(100000000);
	if (ph->g->ac == 6)
	{
		while (i < ph->g->eat_nb)
		{
			if (i == ph->g->eat_nb)
			{
				ft_printf("all philo eat\n");
				return (NULL);
			}
			if (mini_rout(ph) == 1)
				break ;
			i++;
		}
	}
	else
	{
		while (1)
			if (mini_rout(ph) == 1)
				break ;
	}
	return (NULL);
}

int	eat(t_philo *ph)
{
	if (ph->g->dead == 1)
		return (1);
	ph->count++;
	if (is_dead(ph) == 1)
		return (1);
	if (ph->id % 2 == 0)
		(pthread_mutex_lock(&ph->forks_l), print(ph, "has taken a fork"),
			pthread_mutex_lock(ph->forks_r));
	else
		(pthread_mutex_lock(ph->forks_r), print(ph, "has taken a fork"),
			pthread_mutex_lock(&ph->forks_l));
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
	if (ph->count < 2)
	{
		if (ph->g->time_now - ph->g->start_time > (size_t)ph->g->t_die)
		{
			print(ph, "is dead");
			ph->g->dead = 1;
			pthread_mutex_unlock(&ph->g->time);
			return (1);
		}
	}
	else
	{
		if (ph->g->time_now - ph->last_meal_time > (size_t)ph->g->t_die)
		{
			print(ph, "is dead");
			ph->g->dead = 1;
			pthread_mutex_unlock(&ph->g->time);
			return (1);
		}
	}
	pthread_mutex_unlock(&ph->g->time);
	return (0);
}

int	mini_rout(t_philo *ph)
{
	pthread_mutex_lock(&ph->g->test);
	if (ph->g->dead == 1)
	{
		pthread_mutex_unlock(&ph->g->test);
		return (1);
	}
	if (eat(ph) == 1)
	{
		pthread_mutex_unlock(&ph->g->test);
		return (1);
	}
	pthread_mutex_unlock(&ph->g->test);
	if (sleep_(ph) == 1)
		return (1);
	return (0);
}

//  ./Philosophers 5 800 200 200 7 verif ce test