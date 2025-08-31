/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:06:06 by nsmail            #+#    #+#             */
/*   Updated: 2025/08/31 22:57:16 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

static void	free_all_(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	count_word_(const char *s, char c)
{
	size_t	count;
	size_t	i;
	char	quote;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		if (s[i] == '"' || s[i] == 39)
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			i++;
		}
		else
		{
			while (s[i] && s[i] != c && s[i] != '"' && s[i] != '\'')
				i++;
		}
	}
	return (count);
}

static char	*malloc_word_(char *str, char c)
{
	size_t	len;
	char	*new_str;

	len = 0;
	while (*str == c)
		str++;
	while (str[len] != c && str[len] != '\0')
	{
		len++;
	}
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, len + 1);
	return (new_str);
}

char	**ft_split_(char const *s, char c)
{
	char	**tab_g;
	size_t	i;

	tab_g = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab_g)
		return (NULL);
	tab_g[count_word(s, c)] = NULL;
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			tab_g[i] = malloc_word((char *)s, c);
			if (!tab_g[i])
				return (free_all(tab_g), NULL);
			while (*s && *s != c)
				s++;
		}
		i++;
	}
	return (tab_g);
}
char	*quote_norm(char *s)
{
	if (*s == '"')
	{
		s++;
		while (*s && *s != '"')
			s++;
		if (*(s + 1))
			s++;
	}
	else if (*s == 39)
	{
		s++;
		while (*s && *s != 39)
			s++;
		if (*(s + 1))
			s++;
	}
	return (s);
}
