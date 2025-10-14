/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:24:12 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/12 17:25:51 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL3_H
#define GNL3_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

char *get_next_line(int fd);

#endif 