/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_flut.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:15 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/29 21:14:40 by nsmail           ###   ########.fr       */
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
	size_t		x;
	size_t		y;
	size_t		z;
}				t_pos;

typedef struct s_nb_utile
{
	int			i;
	int			j;
	int			fd;
	char		**map;
	char		*ligne;
	char		*temp_gnl;
	int			height;
	int			length;
	int			res_count_word;
	int			len_argv1;
}				t_nb_utile;

typedef struct s_pixel_put
{
	int			x_pix;
	int			y_pix;
}				t_pixel_put;

typedef struct s_mlx
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*ptr_mlx;
	void		*mlx_win;
	t_pixel_put	*pixel;
	t_nb_utile	*nb;
}				t_mlx;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

int				main(int ac, char **av);
int				parsing_general(t_nb_utile *nb, char *argv1);
int				one_big_line(t_nb_utile *nb);
int				count_word(t_nb_utile *nb);
int				compare_height_ligne(t_nb_utile *nb);
int				argv1_good_format(t_nb_utile *nb, char *argv1);
void			test_mlx(t_mlx *mlx);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int				key_hook(int keycode, t_mlx *mlx);
void			display_point(t_mlx *mlx);

#endif