/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:47:47 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/16 14:42:09 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_val(char *str)
{
    int open = 0;
    int close = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else 
                close++;
        }
    }
    return (open + close);
}

void rip(char *str, int must_fix, int n_fix, int pos)
{
    if (must_fix == n_fix && !is_val(str))
    {
        puts(str);
        return;
    }
    for(int i = pos ; str[i]; i++)
    {
        if (str[i] == ')' || str[i] == '(')
        {
            int c = str[i];
            str[i] = ' ';
            rip(str, must_fix, n_fix + 1, i);
            str[i] = c;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    int m_fix = is_val(av[1]);
    rip(av[1], m_fix, 0, 0);
}
