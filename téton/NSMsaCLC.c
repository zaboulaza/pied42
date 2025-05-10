/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NSMsaCLC.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:01:58 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/05/10 20:05:09 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_and_cpy(char *TMP, char *final, char *TMP_TMP)
{
    size_t i;
    size_t end;

    i = 0;
    while (TMP[i] != '\n')
        i++;
    end = i;
    final = malloc(end + 1);
    if (!final)
        return (NULL);
    final[end + 1] = '\0';
    while (i--)
        final[i] = TMP[i];
    free(TMP_TMP);
    TMP_TMP = ft_substr(TMP, end, ft_strlen(TMP) - end);
    return (final);
}

char *cpy(const char *s1, char *s2)
{
    size_t i;

    i = 0;
    s2 = malloc(ft_strlen(s1) + 1);
    if (!s2)
        return (NULL);
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char *get_next_line(int fd)
{
    char *buf;
    ssize_t bytes_read;
    static char *TMP;
    char *TMP_TMP;
    char *final;
    
    TMP_TMP = NULL;
    buf = malloc(BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || !buf)
        return (NULL);

    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (free(buf), NULL);
    buf[bytes_read] = '\0';

    TMP = ft_strjoin(TMP, buf);
    if (ft_strchr(TMP, '\n'))
    {
        find_and_cpy(TMP, final, TMP_TMP);
        TMP = TMP_TMP;
        return (final);
    }
    TMP_TMP = cpy(TMP, TMP_TMP);
    free(TMP);
    TMP = ft_strjoin(TMP_TMP, buf);
    free(buf);
    return NULL;
}
