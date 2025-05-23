/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:47:56 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/18 19:53:46 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	j = i;
	while (stash[i])
		i++;
	if (j == i)
		return (stash[0] = 0, stash);
	rest = ft_substr(stash, j + 1, i);
	if (!rest)
		return (free(stash), stash = 0, NULL);
	return (free(stash), stash = 0, rest);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = stash[i];
	return (line);
}

char	*read_and_stash(int fd, char *stash, char *buf, ssize_t bytes_read)
{
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(buf), free(stash), stash = NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0)
		return (free(buf), stash);
	if (bytes_read < 0)
		return (free(buf), free(stash), stash = NULL);
	buf[bytes_read] = '\0';
	if (!stash)
		stash = ft_strdup("");
	stash = ft_strjoin(stash, buf);
	if (!stash)
		return (free(buf), NULL);
	while (ft_strchr(buf, '\n') == NULL && ft_strchr(buf, '\0'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(buf), stash);
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[BUFFER_MAX] = {0};
	char		*line;
	char		*buf;
	ssize_t		bytes_read;

	if (fd > BUFFER_MAX || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = NULL;
	bytes_read = 0;
	stash[fd] = read_and_stash(fd, stash[fd], buf, bytes_read);
	if (!stash[fd])
		return (free(stash[fd]), stash[fd] = NULL);
	line = extract_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL);
	if (stash[fd])
		stash[fd] = clean_stash(stash[fd]);
	if (!stash[fd])
		return (free(line), stash[fd] = NULL);
	if (stash[fd][0] == 0)
	{
		free(stash[fd]);
		stash[fd] = 0;
	}
	return (line);
}
