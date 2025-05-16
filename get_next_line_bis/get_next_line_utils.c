/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:27:39 by nsmail            #+#    #+#             */
/*   Updated: 2025/05/16 11:17:59 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	tailleg;
	size_t	i;
	size_t	j;
	char	*s3;

	tailleg = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	s3 = malloc(tailleg + 1);
	if (!s3)
		return (free(s1), NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(const char *s)
{
	size_t	tailleg;
	size_t	i;
	char	*sdup;

	i = 0;
	tailleg = ft_strlen(s);
	sdup = malloc(tailleg + 1);
	if (!sdup)
		return (NULL);
	while (i < tailleg)
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_l;
	char	*str;

	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	if (start >= s_l)
		return (ft_strdup(""));
	if (start + len > s_l)
		str = malloc(s_l - start + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i + start] && i <= len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
