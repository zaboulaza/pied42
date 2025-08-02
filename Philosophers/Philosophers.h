/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:11:54 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/02 04:37:16 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "./libft/libft.h"
# include "stdio.h"
# include <limits.h>
# include <pthread.h>

typedef struct s_general
{
	int					ac;
	char				**av;
	int					nb_philo;
	size_t				start_time;
	size_t				last_meal_time;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					eat_nb;
	pthread_mutex_t		print;
	struct s_philo		*ph;
}						t_general;

typedef struct s_philo
{
	int					id;
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
void					creat_thread(t_general *g);
void					init_fork(t_general *g);
void					eat(t_philo *ph);
void					print(t_philo *ph, char *str);
void					sleep(t_philo *ph);
// void		print_list(t_general *g);

#endif