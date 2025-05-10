//#include "libft.h"

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
        return (c +32);
    else
        return (c);
}

#include <ctype.h>
#include <stdio.h>

int main()
{
    printf("Nour test oui -- A ---->%c\n", ft_tolower('A'));
    printf("Nour test non -- x ---->%c\n", ft_tolower('x'));

    printf("vrai test oui -- A ---->%c\n", tolower('A'));
    printf("vrai test non -- x ---->%c\n", tolower('x'));
}