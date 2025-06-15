/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_flut.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:07:15 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 11:44:07 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FLUT_H
# define FILS_DE_FLUT_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef WIN_LENGTH
#  define WIN_LENGTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

// # ifndef ZOOM
// #  define ZOOM 2
// # endif
# define EXIT_FAILURE 1

# define ESCAPE 65307

# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define TOP_ARROW 65362
# define BOTTOM_ARROW 65364

# define EIGHT 65431
# define FOUR 65430
# define TWO 65433
# define SIX 65432

# define RIGHT_ROTATION_NINE 65434
# define LEFT_ROTATION_SEVEN 65429

# define ZOOM_PLUS 65451
# define DEZOOM_LESS 65453
# define ZOOM_ASTERIX 65450
# define DEZOOM_SLASH 65455

typedef struct s_nb_utile
{
	char		**map;
	char		*ligne;
	char		*temp_gnl;
	char		**tokens;
	int			len_argv1;
	int			i;
	int			j;
	int			k;
	int			fd;
	int			height;
	int			length;
	int			res_count_word;
}				t_nb_utile;

typedef struct s_pixel_put
{
	int			x_pix;
	int			y_pix;
}				t_pixel_put;

typedef struct s_mlx
{
	void		*img;
	void		*ptr_mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			r;
	int			g;
	int			b;
}				t_point;

typedef struct s_Z_Min_Max
{
	int			max;
	int			min;
}				t_Z_Min_Max;

typedef struct s_bresenham
{
	int			dx;
	int			dy;
	int			des;
	int			i;
	int			x;
	int			y;
	int			xx;
	int			yy;
	int			color_gradent;
}				t_bresenham;

typedef struct s_camera
{
	float		alpha;
	float		beta;
	float		gamma;
	float		zoom;
}				t_camera;

typedef struct s_general
{
	t_mlx		*mlx;
	t_nb_utile	*nb;
	t_pixel_put	*pix;
	t_point		**tab;
	t_bresenham	*b;
	t_Z_Min_Max	*z;
	t_camera	*cam;
}				t_general;

int				main(int ac, char **av);
int				parsing_general(t_general *g, char *argv1);
int				one_big_line(t_general *g);
int				count_word(t_general *g);
int				compare_height_ligne(t_general *g);
int				argv1_good_format(t_general *g, char *argv1);
void			test_mlx(t_general *g);
void			my_mlx_pixel_put(t_general *g, int x, int y, int color);
int				key_hook(int keycode, t_general *g);
void			display_point(t_general *g);
void			creat_struct(t_general *g);
int				ft_atoi_base(const char *str, int str_base);
int				is_valid(char c, int str_base);
int				after(char *s, t_general *g);
int				before(char *s);
void			remplisage(t_general *g);
void			draw_line_between(t_general *g, t_point a, t_point b);
void			more_than_1(t_general *g, t_point a, t_point b);
void			less_than_1(t_general *g, t_point a, t_point b);
void			draw_map(t_general *g);
void			draw_line(t_general *g, int x, int y);
void			isometrique_projection(t_point *p);
float			fraction(int x, int y, t_point *a, t_point *b);
int				get_color(int x, int y, t_point *a, t_point *b);
void			init(t_general *g);
void			centre_zoom(t_general *g, t_point *a, t_point *b);
void			rotate_z(t_point *p, float gamma);
void			rotate_y(t_point *p, float beta);
void			rotate_x(t_point *p, float alpha);
void			move(int keycode, t_general *g);
void			zoom(int keycode, t_general *g);
int				close_win(t_general *g);
void			free_struct(t_general *g);

#endif