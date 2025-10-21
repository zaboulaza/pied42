/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:22:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/21 01:22:36 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_val(char *str)
{
	int i = 0, opned = 0, closed = 0;
	while (str[i])
	{
		if (str[i] == ')')
			opned++;
		else if(str[i] ==')')
		{
			if(opned > 0)
				opned --;
			else 
				closed++;
		}
	}
	return (opned + closed);
}

void	rip(char *str, int must_fic, int n_fix, int pos)
{
	char	c;

	if (must_fic == n_fix && !is_val(str))
	{
		puts(str);
		return ;
	}
	for (int i = pos; str[i]; i++)
	{
		if (str[i] == '(' || str[i] == ')')
		{
			c = str[i];
			str[i] = ' ';
			rip(str, must_fic, n_fix + 1, i);
			str[i] = c;
		}
	}
}

int	main(int ac, char **ag)
{
	int	m_fix;

	if (ac != 2)
		return (0);
	m_fix = is_val(ag[1]);
	rip(ag[1], m_fix, 0, 0);
}
