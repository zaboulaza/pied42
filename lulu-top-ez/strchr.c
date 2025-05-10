//#include "libft.h"
#include <stddef.h>

char *ft_strchr(const char *str, int c)
{
    size_t i;

    i = 0;
    
    while (str[i])
    {
        if (str[i] != (unsigned char)c)
            i++;
        else
            return ((char *)(str + i));
    }
    if (c == '\0')
    {
        return ((char *)(str + i));
    }
    return (NULL);
}

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Nour -- test ----> %p\n", ft_strchr("le malicieux", 'm'));
    printf("Nour -- test ----> %p\n", strchr("le malicieux", 'm'));
}