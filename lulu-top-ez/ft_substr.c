// #include "libft.h"
#include <stddef.h>
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    size_t j;
    char *sf;

    i = start;
    j = 0;

    if (start >= ft_strlen(s))
    {
        sf = malloc(1);
        if (!sf)
            return (NULL);
        sf[0] = '\0';
        return (sf);
    }

    if (start < ft_strlen(s) && start + len > ft_strlen(s))
    {
        sf = malloc(ft_strlen(s) - start + 1);
        if (!sf)
            return (NULL);
        while (j < ft_strlen(s) - start)
        {
            sf[j] = s[i];
            i++;
            j++;
        }
        sf[j] = '\0';
        return (sf);
    }

    if (start + len <= ft_strlen(s))
    {
        sf = malloc(len + 1);
        if (!sf)
            return (NULL);
        while (j < len)
        {
            sf[j] = s[i];
            i++;
            j++;
        }
        sf[j] = '\0';
        return (sf);
    }
    return (NULL);
}

#include <stdio.h>

int main()
{
    const char s[] = "zaboulaza";

    printf("Nour test -- zabou ----> %s\n", ft_substr(s, 0, 5));
}