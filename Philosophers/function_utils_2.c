/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 06:46:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/14 23:19:11 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	print(t_philo *ph, char *str)
{
	size_t	timestamp;
	size_t	time_now;

	time_now = get_time_in_ms();
	timestamp = time_now - ph->g->start_time;
	pthread_mutex_lock(&ph->g->print);
	printf("%zu philo[%d] %s\n", timestamp, ph->id, str);
	pthread_mutex_unlock(&ph->g->print);
}

int	is_philo_dead(t_general *g)
{
	int	dead;

	pthread_mutex_lock(&g->dead_mut);
	dead = g->dead;
	pthread_mutex_unlock(&g->dead_mut);
	return (dead);
}
