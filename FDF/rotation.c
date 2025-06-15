/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:36:53 by nsmail            #+#    #+#             */
/*   Updated: 2025/06/14 15:54:10 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fils_de_flut.h"

void	rotate_z(t_point *p, float gamma)
{
	int	tmp;

	tmp = p->x;
	p->x = tmp * cos(gamma) - p->y * sin(gamma);
	p->y = tmp * sin(gamma) + p->y * cos(gamma);
}

void	rotate_y(t_point *p, float beta)
{
	int	tmp;

	tmp = p->x;
	p->x = tmp * cos(beta) + p->z * sin(beta);
	p->z = p->z * cos(beta) - tmp * sin(beta);
}

void	rotate_x(t_point *p, float alpha)
{
	int	tmp;

	tmp = p->y;
	p->y = tmp * cos(alpha) - p->z * sin(alpha);
	p->z = tmp * sin(alpha) + p->z * cos(alpha);
}
