//#include "libft.h"
#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
    {
        return (0);
    }
    

    while (i < n)
    {
        if (s1[i] == s2[i])
            i++;
        else
            return (s1[i] - s2[i]);
    }
    return (0);
}

#include <string.h>
#include <stdio.h>

int main()
{
    char s1[] = "lulu top ez";
    char s2[] = "lulu top ez";

    printf("Nour test -- 0 ----> %d\n", ft_strncmp(s1, s2, sizeof(s1)));
    printf("Vrai test -- 0 ----> %d\n", strncmp(s1, s2, sizeof(s1)));

    char s3[] = "lulu top dz";
    char s4[] = "lulu top ez";

    printf("Nour test -- -neg ----> %d\n", ft_strncmp(s3, s4, sizeof(s3)));
    printf("Vrai test -- -neg ----> %d\n", strncmp(s3, s4, sizeof(s3)));

    char s5[] = "lulu top fz";
    char s6[] = "lulu top ez";

    printf("Nour test -- +pos ----> %d\n", ft_strncmp(s5, s6, sizeof(s5)));
    printf("Vrai test -- +pos ----> %d\n", strncmp(s5, s6, sizeof(s5)));
}