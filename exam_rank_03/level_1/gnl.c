/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:33:35 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/20 16:49:41 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl.h"

char	*ft_strdup(char *line)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (line[len])
	{
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
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
	static int	buffer_pos = 0;
	static int	buffer_read = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[1000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read == 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
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

	fd = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
