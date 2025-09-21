/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:34:47 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/21 13:59:33 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL2_H
#define GNL2_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

char	*get_next_line(int fd);

#endif