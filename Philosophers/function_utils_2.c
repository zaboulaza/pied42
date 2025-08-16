/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 06:46:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/17 00:10:04 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	print(t_philo *ph, char *str)
{
	size_t	timestamp;
	size_t	time_now;

	if (!ph || !ph->g)
		return ;
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

int	check_usleep(t_general *g)
{
	int	i;

	i = 0;
	while (i < g->nb_philo)
	{
		if (is_dead(&g->ph[i]) == 1 || is_philo_dead(g) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*str;
	size_t	tailleg;

	tailleg = nmenb * size;
	str = malloc(tailleg);
	if (!str)
		return (NULL);
	ft_bzero(str, tailleg);
	return (str);
}

void	ft_bzero(void *ptr, size_t n)
{
	while (n--)
		*(unsigned char *)ptr++ = '\0';
}
