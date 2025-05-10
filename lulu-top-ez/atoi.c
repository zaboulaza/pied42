// #include "libft.h"
#include <stddef.h>

int ft_atoi(const char *nb)
{
    int res;
    size_t i;
    int signe;

    i = 0;
    res = 0;
    signe = 1;

    while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
        i++;
    if (nb[i] == '-' || nb[i] == '+')
    {
        if (nb[i] == '-')
        {
            signe = -1;
        }
        i++;
    }
    while (nb[i] >= '0' && nb[i] <= '9')
    {
        res = (res * 10) + (nb[i] - '0');
        i++;
    }
    res *= signe;
    return (res); 
}

#include <stdio.h>
#include <string.h>

int main()
{
    char nb[] = "  -124hj";
    printf("Nour test -- -124 ----> %d\n", ft_atoi(nb));
    // printf("Vrai test -- -124 ----> %d\n", atoi(nb));
}