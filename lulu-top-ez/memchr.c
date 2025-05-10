//#include "libft.h"
#include <stddef.h>

void *ft_memchr(const void *ptr, int c, size_t n)
{
    size_t i;

    i = 0;
    const unsigned char *ptr1;
    unsigned char c1;

    c1 = (unsigned char)c;
    ptr1 = (const unsigned char *)ptr;

    if (!ptr)
        return (NULL);

    while (i < n)
    {
        if (ptr1[i] == c1)
            return ((void*)(ptr1 + i));
        i++;
    }
    return (NULL);
}

#include <string.h>
#include <stdio.h>

int main()
{
    const unsigned char ptr[] = "lulu ez top";
    unsigned char c = 'e';

    printf("Nour -- test ----> %p\n", ft_memchr(ptr, c, 11));
    printf("Vrai -- test ----> %p\n", memchr(ptr, c, 11));
}