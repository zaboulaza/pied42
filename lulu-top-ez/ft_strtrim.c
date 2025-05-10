#include <string.h>
#include <stddef.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

int is_in_set(char c, const char *set)
{
    size_t j;

    j = 0;
    while (set[j])
    {
        if (c == set[j])
            return (1);
        j++;       
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t start;
    size_t end;
    char *str;

    i = 0;
    while (s1[i] && is_in_set(s1[i], set))
        i++;
    start = i;

    i = ft_strlen(s1) - 1;
    while (s1[i] && is_in_set(s1[i], set))
        i--;
    end = i;
    
    str = malloc((end - start + 1) + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (start <= end)
    {
        str[i] = s1[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}

#include <stdio.h>

int		main()
{
	const char str[] = "  a!je suis la! et toi ?   ";
	const char ret[] = " ";

    printf("Vrai test ----> %s\n", ft_strtrim(str, ret));
}