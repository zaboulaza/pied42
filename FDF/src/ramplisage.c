/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramplisage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:09:42 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/15 14:08:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fils_de_flut.h"

void	remplisage(t_general *g)
{
	int	y;
	int	x;

	y = 0;
	init(g);
	while (y < g->nb->height)
	{
		g->nb->tokens = ft_split(g->nb->map[y], ' ');
		free(g->nb->map[y]);
		x = 0;
		while (g->nb->tokens[x])
		{
			g->tab[y][x].x = x;
			g->tab[y][x].y = y;
			g->tab[y][x].z = before(g->nb->tokens[x]);
			g->tab[y][x].color = after(g->nb->tokens[x], g);
			g->tab[y][x].r = (g->tab[y][x].color >> 16) & 0xFF;
			g->tab[y][x].g = (g->tab[y][x].color >> 8) & 0xFF;
			g->tab[y][x].b = (g->tab[y][x].color) & 0xFF;
			free(g->nb->tokens[x]);
			x++;
		}
		free(g->nb->tokens);
		y++;
	}
	free(g->nb->map);
}

int	before(char *s)
{
	int		i;
	char	*s2;
	int		sfinal;

	i = 0;
	sfinal = 0;
	if (strchr(s, ','))
	{
		while (s[i] != ',')
			i++;
		s2 = malloc(i + 1);
		if (!s2)
			return (0);
		i = -1;
		while (s[++i] != ',')
			s2[i] = s[i];
		s2[i] = '\0';
		sfinal = ft_atoi(s2);
		free(s2);
		return (sfinal);
	}
	sfinal = ft_atoi(s);
	return (sfinal);
}

int	after(char *s, t_general *g)
{
	char	*color;
	int		color_int;

	g->nb->i = 0;
	g->nb->j = 0;
	g->nb->k = 0;
	if (strchr(s, ','))
	{
		while (s[g->nb->i] != ',')
			g->nb->i++;
		g->nb->k = g->nb->i + 3;
		while (s[g->nb->i])
			g->nb->i++;
		color = malloc(g->nb->i - g->nb->k + 1);
		if (!color)
			return (16777215);
		while (s[g->nb->k])
			color[g->nb->j++] = s[g->nb->k++];
		color[g->nb->j] = '\0';
		color_int = ft_atoi_base(color, 16);
		free(color);
		return (color_int);
	}
	return (16777215);
}

int	is_valid(char c, int str_base)
{
	int		i;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	i = 0;
	while (i < str_base)
	{
		if (c == lower[i] || c == upper[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	neg;
	int	res;

	res = 0;
	neg = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && is_valid(str[i], str_base))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * str_base) + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = (res * str_base) + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = (res * str_base) + (str[i] - 'A' + 10);
		i++;
	}
	return (res * neg);
}
