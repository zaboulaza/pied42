/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:11:54 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/17 22:26:38 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_general
{
	int					ac;
	char				**av;
	int					nb_philo;
	size_t				start_time;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					eat_nb;
	int					dead;
	int					compt;
	int					all_ready_print;
	pthread_mutex_t		print;
	pthread_mutex_t		time;
	pthread_mutex_t		test;
	pthread_mutex_t		dead_mut;
	size_t				time_now;
	struct s_philo		*ph;
}						t_general;

typedef struct s_philo
{
	int					id;
	int					count;
	size_t				last_meal_time;
	pthread_mutex_t		last_meal_mutex;
	pthread_mutex_t		forks_l;
	pthread_mutex_t		*forks_r;
	pthread_t			thread;
	struct s_general	*g;
}						t_philo;

int						main(int ac, char **av);
void					creat_struct(t_general *g, int ac, char **av);
int						parsing_general(t_general *g);
int						verif_good_cara(t_general *g);
void					free_struct(t_general *g);
long long				ft_atol(char *nb);
int						atoi_(t_general *g);
int						start_code(t_general *g);
void					*philo_routine(void *arg);
int						creat_thread(t_general *g);
void					init_fork(t_general *g);
int						sleep_(t_philo *ph);
int						eat(t_philo *ph);
void					print(t_philo *ph, char *str);
size_t					get_time_in_ms(void);
int						is_dead(t_philo *ph);
int						mini_rout(t_philo *ph);
int						is_philo_dead(t_general *g);
int						check_usleep(t_general *g);
void					ft_bzero(void *ptr, size_t n);
void					*ft_calloc(size_t nmenb, size_t size);
int						uslp_eat(t_philo *ph, size_t start);
void					norm1_eat(t_philo *ph);
void					norm1_philo_rout(t_philo *ph, int i);

// void		print_list(t_general *g);

#endif