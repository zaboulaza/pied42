//#include "libft.h"

int ft_isalnum(int c)
{
    if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("mien teste bon -- A ---->%d\n", ft_isalnum('A'));
    printf("mien teste bon -- 9 ---->%d\n", ft_isalnum('9'));
    printf("mien teste bon -- v ---->%d\n", ft_isalnum('v'));
    printf("mien teste faux -- : ---->%d\n", ft_isalnum(':'));

    printf("vrai teste bon -- A ---->%d\n", isalnum('A'));
    printf("vrai teste bon -- 9 ---->%d\n", isalnum('9'));
    printf("vrai teste bon -- v ---->%d\n", isalnum('v'));
    printf("vrai teste faux -- : ---->%d\n", isalnum(':'));
}