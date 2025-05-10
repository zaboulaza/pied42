//#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;

    i = 0;
    unsigned char *dest1;
    const unsigned char *src1;
    unsigned char *temp = malloc(sizeof(unsigned char) * n);
    if (!temp)
        return (NULL);

    dest1 = (unsigned char *)dest;
    src1 = (const unsigned char *)src;
    if(!dest || !src)
        return (NULL);
    while (i < n)
    {
        temp[i] = src1[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        dest1[i] = temp[i];
        i++;
    }
    free(temp);
    return (dest);
}

#include <string.h>
#include <stdio.h>
int main()
{
    unsigned char dest[20] = "Hello, World!";
    const unsigned char src1[] = "lulu top ez";

    ft_memmove(dest, src1, sizeof(src1));
    printf("Nour -- test ----> %s\n", dest);

    memmove(dest, src1, sizeof(src1));
    printf("Vrai -- test ----> %s\n", dest);

    return 0;
}