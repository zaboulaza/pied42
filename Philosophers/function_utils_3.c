/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:10:19 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/17 22:49:56 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	uslp_eat(t_philo *ph, size_t start)
{
	size_t	now;

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
	return (0);
}

void	norm1_eat(t_philo *ph)
{
	print(ph, "has taken a fork");
	print(ph, "has taken a fork");
	print(ph, "is eating");
	pthread_mutex_lock(&ph->last_meal_mutex);
	ph->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&ph->last_meal_mutex);
}

void	norm1_philo_rout(t_philo *ph, int i)
{
	while (i <= ph->g->eat_nb)
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
