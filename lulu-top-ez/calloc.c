// #include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *ptr, size_t n)
{
    size_t i;

    i = 0;
    unsigned char *ptr1 = (unsigned char *)ptr;
    while (i < n)
    {
        ptr1[i] = '\0';
        i++;
    }
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *memory;
    size_t tailg;

    if (nmemb == 0 || size == 0)
        return (NULL);

    tailg = nmemb * size;
    memory = malloc(tailg);

    if (memory == 0)
        return (NULL);

    ft_bzero(memory, tailg);
    return(memory);
}

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Nour test -- vide ----> %p\n", ft_calloc(5, sizeof(char)));
    printf("Vrai test -- vide ----> %p\n", calloc(5, sizeof(char)));
}