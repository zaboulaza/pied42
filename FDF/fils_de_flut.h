/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_flut.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:15 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/24 10:19:39 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FLUT_H
# define FILS_DE_FLUT_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	size_t	x;
	size_t	y;
	size_t	z;
}			t_pos;

typedef struct s_nb_utile
{
	int		i;
	int		j;
	int		fd;
	char	**map;
	char	*ligne;
	char	*temp_gnl;
	int		height;
	int		length;
	int		res_count_word;
}			t_nb_utile;

int			main(int ac, char **av);
int			parsing_general(t_nb_utile *nb);
int			one_big_line(t_nb_utile *nb);
int			count_word(t_nb_utile *nb);
int			compare_height_ligne(t_nb_utile *nb);

#endif