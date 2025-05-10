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

int size(int n)
{
    int tailleg;

    tailleg = 1;
    if (n < 0)
    {
        tailleg++;
        n = -n;
    }
    while (n > 9)
    {
        n = n /10;
        tailleg++;
    }
    return (tailleg);
}

char *ft_itoa(int n)
{
    char *str;
    int tailleg;
    int nb;

    nb = n;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n == 0)
            return (ft_strdup("0"));
    tailleg = size(n);
    str = malloc(tailleg + 1);
    if (!str)
        return (NULL);
    if (n < 0)
        nb = -nb;
    str[tailleg] = '\0';
    tailleg = tailleg - 1;
    while (tailleg >= 0)
    {
        str[tailleg] = (nb % 10) + '0';
        nb = nb /10;
        tailleg--;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}

#include <stdio.h>

int main()
{
    int n = -12584825;
    printf("Nour test -- '-125' ----> %s\n", ft_itoa(n));
}