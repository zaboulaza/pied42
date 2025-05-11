/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:04:47 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/05/11 04:20:09 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *clean_stash(char *stash)
{
    size_t i;
    size_t j;
    char *rest;
    
    if (!stash)
        return(NULL);
    if (ft_strchr(stash, '\n'))
    {
        i = 0;
        while (stash[i] != '\n')
            i++;
        j = i;
        while (stash[i])
            i++;
        rest = ft_substr(stash, j, i);
        free(stash);
        return (rest);
    }
    return (NULL);
}

char *extract_line(char *stash)
{
    size_t i;

    char *line;
    if (!stash)
        return(NULL);
    if (ft_strchr(stash, '\n'))
    {
        i = 0;
        while (stash[i] != '\n')
            i++;
        line = malloc(i + 2);
        if (!line)
            return (NULL);
        line[i + 1] = '\0';
        line[i] = '\n';
        while (i--)
            line[i] = stash[i];
        return (line);
    }
    return (NULL);
}

char *read_and_stash(int fd, char *stash)
{
    char *buf;
    ssize_t bytes_read;
    char *tmp;
    
    buf = malloc(BUFFER_SIZE +  1);
    if (!buf || BUFFER_SIZE <= 0 || fd < 0)
        return (free(buf), NULL);
    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read <= 0)
        return(free(buf), stash);
    buf[bytes_read] = '\0';
    tmp = stash;
    stash = ft_strjoin(stash, buf);
    free(tmp);
    while (ft_strchr(buf, '\n') == NULL)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            return(free(buf), stash);
        buf[bytes_read] = '\0';
        tmp = stash;
        stash = ft_strjoin(stash, buf);
        free(tmp);
    }
    return (free (buf), stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    stash = read_and_stash(fd, stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    if (!line)
        return (NULL);
    stash = clean_stash(stash);
    if (!stash)
        return (NULL);
    return (line);
}
