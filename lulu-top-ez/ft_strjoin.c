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

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t i;
    size_t j;
    size_t tailleg;
    char *s3;

    i = 0;
    j = 0;

    tailleg = ft_strlen(s1) + ft_strlen(s2);
    s3 = malloc((tailleg * sizeof(char)) + 1);
    if (!s3)
        return (NULL);
    
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[i] = s2[j];
        j++;
        i++;
    }
    s3[i] = '\0';

    return (s3);
}

#include <stdio.h>

int main()
{
    const char s1[] = "nul le ";
    const char s2[] = "poney";

    printf("Nour test -- nul le poney ----> %s\n", ft_strjoin(s1, s2));
}