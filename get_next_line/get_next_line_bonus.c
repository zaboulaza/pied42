/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:27:47 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/15 22:59:03 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*rest;

	// if (!stash || !*stash)
	// 	return (NULL);
	i = 0;
	// printf("test 3: clean_stash #stash 1 ----> [%s\n \n", stash);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	j = i;
	while (stash[i])
		i++;
	// printf("i = %zu\n", i);
	// printf("j = %zu\n \n", j);
	// if (stash[i] == '\0')
	// 	return (ft_free(stash), NULL);
	// printf("test 3: clean_stash #stash 2 ----> [%s\n \n", stash);
	if (j == i)
		return (stash[0] = 0, stash);/////
	rest = ft_substr(stash, j + 1, i);
	if (!rest)
		return (ft_free(stash), stash = 0, NULL);
	// printf("test 3: clean_stash ----> [%s\n \n", rest);
	return (ft_free(stash), stash = 0, rest);
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
	// printf("sizemal :%i\n", i + 1);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = stash[i];
	// printf("test 2: extract_line ----> [%s\n \n", line);
	return (line);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || BUFFER_SIZE <= 0 || fd < 0)
		return (free(buf), ft_free(stash), stash = NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0 )
		return (free(buf), stash);
	if (bytes_read < 0)
		return(free(buf), ft_free(stash), stash = NULL);
	buf[bytes_read] = '\0';
	// printf("test : read_and_stash [%s]\n \n", stash);
	if (!stash)
		stash = ft_strdup("");
	if (!stash) //
		return (free(buf), NULL);//
	stash = ft_strjoin(stash, buf);
	if (!stash) //
		return (free(buf), NULL);//
	while (ft_strchr(buf, '\n') == NULL && ft_strchr(buf, '\0'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			return (free(buf), stash);
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash) //
			return (free(buf), NULL);//
	}
	// printf("test 1: read_and_stash [%s\n \n", stash);
	return (free(buf), stash);
}
void ft_free(char *ptr)
{
	if (ptr)
		free(ptr);
}
char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

//	printf("Reste au debut : <%s>", stash);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (ft_free(stash[fd]), stash[fd] = NULL);
	line = extract_line(stash[fd]);
	if (!line)
		return (ft_free(stash[fd]), stash[fd] = NULL);
	if (stash[fd])
		stash[fd] = clean_stash(stash[fd]);
	if (!stash[fd])
		return (free(line), stash[fd] = NULL);
	if (stash[fd][0] == 0)
	{
		ft_free(stash[fd]);
		stash[fd] = 0;
	}
	// printf("[le rest dans mon stash ----> stash : %s]\n\n", stash);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	printf("%d\n \n", BUFFER_SIZE);
// 	fd = open("fichier.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	// line = get_next_line(fd);
// 	// printf("ligne lue: [%s]\n", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("ligne lue: [%s]\n", line);
// 	// free(line);
// 	while (((line = get_next_line(fd)) != NULL))
// 	{
// 		printf("ligne lue: [%s]", line);
// 		free(line);
// 	}
// 	printf("ligne lue: [%s]", line = get_next_line(fd));
// 	free(line);
// 	close(fd);
// }
// // cc -g3






// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (unsigned char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((unsigned char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	size_t	tailleg;
// 	size_t	i;
// 	size_t	j;
// 	char	*s3;

// 	tailleg = ft_strlen(s1) + ft_strlen(s2);
// 	i = 0;
// 	s3 = malloc(tailleg + 1);
// 	if (!s3)
// 		return (free(s3), NULL);
// 	while (s1[i])
// 	{
// 		s3[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		s3[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	s3[i] = '\0';
// 	return (s3);
// }

// char	*ft_strdup(const char *s)
// {
// 	size_t	tailleg;
// 	size_t	i;
// 	char	*sdup;

// 	i = 0;
// 	tailleg = ft_strlen(s);
// 	sdup = malloc(tailleg + 1);
// 	if (!sdup)
// 		return (NULL);
// 	while (i < tailleg)
// 	{
// 		sdup[i] = s[i];
// 		i++;
// 	}
// 	sdup[i] = '\0';
// 	return (sdup);
// }

// #include <stdio.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	s_l;
// 	char	*str;

// 	if (!s)
// 		return (NULL);
// 	s_l = ft_strlen(s);
// 	if (start >= s_l)
// 		return (ft_strdup(""));
// 	if (start + len > s_l)
// 		str = malloc(s_l - start + 3);
// 	else
// 		str = malloc(len + 3);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s[i + start] && i <= len)
// 	{
// 		str[i] = s[i + start];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }