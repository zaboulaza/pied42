/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:27:44 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/15 21:12:52 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#define BUFFER_MAX 1024

char *get_next_line(int fd);
char *clean_stash(char *stash);
char *extract_line(char *stash);
char *read_and_stash(int fd, char *stash);
char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, const char *s2);
char *ft_strdup(const char *s);
char *ft_substr(const char *s, unsigned int start, size_t len);
void ft_free(char *ptr);

#endif