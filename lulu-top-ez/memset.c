//#include "libft.h"
#include <stddef.h>

void *ft_memset(void *ptr, int c, size_t n)
{
    size_t  i;

    i = 0;
    unsigned char *ptr1 = (unsigned char *)ptr;

    while (i < n)
    {
        ptr1[i] = (unsigned char)c;
        i++;
    }

    return (ptr);
}

#include <string.h>
#include <stdio.h>
int main ()
{
    char test[] = "lulu top ap ez";
    printf("lulu top ap ez -- sans rien ----> %s\n", test);

    ft_memset (test, '!', 4);
    printf("lulu top ap ez -- le mien ----> %s\n", test);

    memset (test, '!', 4);
    printf("lulu top ap ez -- le vrai ----> %s\n", test);
}