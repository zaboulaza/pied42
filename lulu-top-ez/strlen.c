//#include "libft.h"
#include <stddef.h>

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

#include <string.h>
#include <stdio.h>

int main()
{
    const char str1[] = "123456789";

    printf("nour test -- 9 ---->%zu\n", ft_strlen(str1));
    
    printf("vrai test -- 9 ---->%zu\n", strlen(str1));
}