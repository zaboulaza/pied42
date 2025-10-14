/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaboulaza <zaboulaza@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:24:05 by nsmail            #+#    #+#             */
/*   Updated: 2025/10/14 20:44:52 by nsmail           ###   ########.fr       */
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
	static int	buff_read = 0;
	static int	buff_pos = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[1000];
	int		i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read(fd, buffer, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_read <= 0)
				break ;
		}
		line[i++] = buffer[buff_pos++];
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
	return (1);
}
