/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:33:50 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/20 14:54:59 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);

#endif