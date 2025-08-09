/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 04:03:45 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/09 15:29:09 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include <sys/time.h>

long long	ft_atol(char *nb)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = (res * 10) + (nb[i] - '0');
		i++;
	}
	return (res);
}

void	creat_thread(t_general *g)
{
	int	i;

	i = 0;
	g->start_time = get_time_in_ms();
	while (i < g->nb_philo)
	{
		g->ph[i].id = i + 1;
		if (pthread_create(&g->ph[i].thread, NULL, philo_routine,
				&g->ph[i]) != 0)
		{
			ft_printf("creation of thread fail\n");
			free_struct(g);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < g->nb_philo)
		pthread_join(g->ph[i++].thread, NULL);
}

void	init_fork(t_general *g)
{
	int	i;

	i = 0;
	g->ph = ft_calloc(g->nb_philo, sizeof(t_philo));
	if (!g->ph)
		exit(1);
	while (i < g->nb_philo)
	{
		pthread_mutex_init(&g->ph[i].forks_l, NULL);
		if (i == g->nb_philo - 1)
			g->ph[i].forks_r = &g->ph[0].forks_l;
		else
			g->ph[i].forks_r = &g->ph[i + 1].forks_l;
		i++;
	}
	i = 0;
	pthread_mutex_init(&g->print, NULL);
	pthread_mutex_init(&g->test, NULL);
	pthread_mutex_init(&g->time, NULL);
	while (i < g->nb_philo)
	{
		g->ph[i].g = g;
		i++;
	}
}

size_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	sleep_(t_philo *ph)
{
	print(ph, "is sleeping");
	usleep(ph->g->t_sleep * 1000);
	// if (is_dead(ph) == 1)
	// 	return (1);
	return (0);
}

// void	init_philo(t_general *g, t_philo *ph)
// {
// 	int	i;

// 	i = 0;
// 	while (i < g->nb_philo)
// 	{
// 		ph[i].g = g;
// 		printf("ph[%d]->g.t_die[%d]\n", i, ph[i].g->t_die);
// 		printf("ph[%d]->g.av[%s]\n", i, ph[i].g->av[i + 1]);
// 		i++;
// 	}
// }
