// #include "libft.h"
#include <stddef.h>
#include <stdlib.h>

size_t ft_strlen(const char *c)
{
    size_t i;

    i = 0;
    while (c[i])
    {
        i++;
    }
    return (i);
}

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *s2;

    i = 0;

    if (!s || !f)
        return (NULL);
    
    s2 = malloc(ft_strlen(s) + 1);
    if (!s2)
        return (NULL);

    while (s[i])
    {
        s2[i] = f(i, s[i]);
        i++;
    }
    s2[i] = '\0';
    return (s2);
}