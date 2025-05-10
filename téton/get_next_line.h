/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:59:40 by zaboulaza         #+#    #+#             */
/*   Updated: 2025/05/10 05:42:19 by zaboulaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif
