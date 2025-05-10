// #include "libft.h"
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

char *ft_strdup(const char *s)
{
    size_t i;
    size_t len;
    char *sdup;

    i = 0;
    len = ft_strlen(s);
    sdup = malloc(len + 1);
    
    if (!sdup)
        return (NULL);

    while (i < len)
    {
        sdup[i] = s[i];
        i++;
    }
    sdup[i] = '\0';

    return (sdup);
}

#include <stdio.h>
#include <string.h>

// int main()
// {
//     const char s[] = "trop nul";

//     printf("Nour test -- trop nul ----> %s\n", ft_strdup(s));
//     printf("Vrai test -- trop nul ----> %s\n", strdup(s));
// }