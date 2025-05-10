//#include "libft.h"
#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
    unsigned char *dest1;
    const unsigned char *src1;

    dest1 = (unsigned char*)dest;
    src1 = (const unsigned char*)src;

    if (!dest || !src)
        return (NULL);
    
    while (i < n)
    {
        dest1[i] = src1[i];
        i++;
    }
    return(dest);
}

#include <string.h>
#include <stdio.h>

int main()
{
    unsigned char dest[20];
    const unsigned char src1[] = "lulu top ez";

    ft_memcpy(dest, src1, sizeof(src1));
    memcpy(dest, src1, sizeof(src1));
    printf("Nour -- test ----> %s\n", dest);
    printf("Vrai -- test ----> %s\n", dest);
}
/*int main( void )
{
    char str1[7] = "aabbcc";
    char str3[7] = "aabbcc";
    char str5[7] = "aabbcc";
    char str6[7] = "bbcc";
    char str7[7] = "aabbcc";
    char str8[7] = "bbcc";
    printf("str 1 = %s     | ", str5);
    printf("str 2 = %s\n", str7);
    ft_memcpy(str5, str6, 2);
    memcpy(str7, str8, 2);
    printf("ft_memcpy = %s | ", str5);
    printf("memcpy = %s\n", str7);
    printf("str 1 = %s     | ", str1);
    printf("str 3 = %s\n", str3);
}*/