/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:11:00 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/16 12:04:57 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl3.h"

char	*ft_strdup(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (line[i])
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static int	pos_buff = 0;
	static int	read_buff = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[10000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (1)
	{
		if (pos_buff >= read_buff)
		{
			read_buff = read(fd, buffer, BUFFER_SIZE);
			pos_buff = 0;
			if (read_buff <= 0)
				break ;
		}
		line[i++] = buffer[pos_buff++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (1);
}
