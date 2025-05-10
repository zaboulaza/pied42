//#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
        return (c -32);
    else
        return (c);
}

#include <ctype.h>
#include <stdio.h>

int main()
{
    printf("Nour test oui -- a ---->%c\n", ft_toupper('a'));
    printf("Nour test non -- X ---->%c\n", ft_toupper('X'));

    printf("vrai test oui -- a ---->%c\n", toupper('a'));
    printf("vrai test non -- X ---->%c\n", toupper('X'));
}