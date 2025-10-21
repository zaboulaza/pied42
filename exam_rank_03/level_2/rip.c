/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:47:47 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/21 02:10:52 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int count_parent(char *str)
{
    int opened = 0, closed = 0;

    for(int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            opened++;
        else if (str[i] == ')')
        {
            if (opened > 0)
                opened--;
            else
                closed++;
        }
    }
    return (opened + closed);
}

void rip(char *str, int must_fix, int nb_fix, int pos)
{
    if (must_fix == nb_fix && !count_parent(str))
    {
        puts(str);
        return;
    }
    for (int i = pos; str[i]; i++)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            int c = str[i];
            str[i] = ' ';
            rip(str, must_fix, nb_fix + 1, i);
            str[i] = c;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    int must_fix = count_parent(av[1]);
    rip(av[1], must_fix, 0, 0);
    return (1);
}
