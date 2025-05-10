//#include "libft.h"
#include <stddef.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strrchr(const char *str, int c)
{
    size_t i;

    i = ft_strlen(str);
    if (c == '\0')
    {
        return ((char *)(str + i));
    }
    while (i > 0)
    {
        if (str[i] != (unsigned char)c)
            i--;
        else
            return ((char *)(str + i));
    }
    if (str[0] == (unsigned char)c)
        return ((char *)str);
    
    return (NULL);
}

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Nour -- test ----> %s\n", ft_strrchr("le malicieux", 'i'));
    printf("Nour -- test ----> %s\n", strrchr("le malicieux", 'i'));
}

