/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:11:52 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/21 03:44:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void tree(char *str)
{
    char tmp;
    for(int i = 0; str[i]; i++)
    {
        for(int j = i + 1; str[j]; j++)
        {
            if (str[i] > str[j])
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

void permut(char *str, int *used, char *line, int n, int len)
{
    if (n ==len)
    {
        for (int i = 0; i < len; i++)
            write(1, &line[i], 1);
        write(1, "\n", 1);
        return;
    }
    for(int i = 0; i < len; i++)
    {
        if (used[i])
            continue;
        used[i] = 1;
        line[n] = str[i];
        permut(str, used, line, n + 1, len);
        used[i] = 0;
    }
}

int main(int ac, char **av)
{
    int *used;
    char *line;
    int len = 0;

    if (ac != 2)
        return (1);
    while (av[1][len])
        len++;
    used = calloc(len, sizeof(int));
    line = malloc(sizeof(char) * (len + 1));
    tree(av[1]);
    permut(av[1], used, line, 0, len);
    free(used);
    free(line);
    return (1);
}
