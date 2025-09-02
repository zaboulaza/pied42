/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_third_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:06:06 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/02 00:24:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	free_all_(char **tab)
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

size_t	count_word_(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != c)
		{
			if (*s == '"' || *s == 39)
				s = quote_norm(s);
			else
				s++;
		}
	}
	return (count);
}

char	*malloc_word_(char *str, char c)
{
	size_t	len;
	char	*new_str;
	char	quote;

	len = 0;
	while (*str == c)
		str++;
	while (str[len] != c && str[len] != '\0')
	{
		if (str[len] == '"' || str[len] == 39)
		{
			quote = str[len++];
			while (str[len] && str[len] != quote)
				len++;
			if (str[len] == quote)
				len++;
		}
		else
			len++;
	}
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, len + 1);
	return (new_str);
}

char	**ft_split_(char *s, char c)
{
	char	**tab_g;
	size_t	i;
	size_t	word_count;
	char	*word;

	word_count = count_word_(s, c);
	tab_g = malloc(sizeof(char *) * (word_count + 1));
	if (!tab_g)
		return (NULL);
	tab_g[word_count] = NULL;
	i = 0;
	while (*s && i < word_count)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word = malloc_word_(s, c);
			if (!word)
				return (free_all_(tab_g), NULL);
			tab_g[i++] = word;
			s += ft_strlen(word);
		}
	}
	return (tab_g);
}

char	*quote_norm(char *s)
{
	char	quote;

	quote = *s++;
	while (*s && *s != quote)
		s++;
	s++;
	return (s);
}
