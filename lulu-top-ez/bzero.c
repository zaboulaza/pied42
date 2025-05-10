//#include "libft.h"
#include <stddef.h>
void ft_bzero(void *ptr, size_t n)
{
    size_t i;

    i = 0;
    unsigned char *ptr1 = (unsigned char *)ptr;
    while(i < n)
    {
        ptr1[i] = '\0';
        i++;
    }
}

#include <string.h>
#include <stdio.h>

int main()
{
    unsigned char ptr[] = "zoubida zoubidou";

    printf("test a vide ----> %s\n", ptr);

    ft_bzero(ptr, sizeof(ptr));
    printf("Nour test a vide ----> %s\n", ptr);

    bzero(ptr, sizeof(ptr));
    printf("Vrai test a vide ----> %s\n", ptr);
}