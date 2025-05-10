//#include "libft.h"
#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    const unsigned char *str1;
    const unsigned char *str2;

    str1 = (const unsigned char *)s1;
    str2 = (const unsigned char *)s2;

    while (i < n)
    {
        if (str1[i] == str2[i])
            i++;
        else
            return (str1[i] - str2[i]);
    }
    return (0);
}

#include <string.h>
#include <stdio.h>

int main()
{
    const unsigned char s1[] = "lulu top ez";
    const unsigned char s2[] = "lulu top ez";

    printf("Nour test -- 0 ----> %d\n", ft_memcmp(s1, s2, sizeof(s1)));
    printf("Vrai test -- 0 ----> %d\n", memcmp(s1, s2, sizeof(s1)));

    const unsigned char s3[] = "lulu top dz";
    const unsigned char s4[] = "lulu top ez";

    printf("Nour test -- -neg ----> %d\n", ft_memcmp(s3, s4, sizeof(s3)));
    printf("Vrai test -- -neg ----> %d\n", memcmp(s3, s4, sizeof(s3)));

    const unsigned char s5[] = "lulu top fz";
    const unsigned char s6[] = "lulu top ez";

    printf("Nour test -- +pos ----> %d\n", ft_memcmp(s5, s6, sizeof(s5)));
    printf("Vrai test -- +pos ----> %d\n", memcmp(s5, s6, sizeof(s5)));
}