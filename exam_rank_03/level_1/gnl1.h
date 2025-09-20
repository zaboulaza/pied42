/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:00:33 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/20 16:09:46 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL1_H
# define GNL1_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);

#endif