//#include "libft.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}


#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("mien teste bon -- 0 ---->%d\n", ft_isdigit('0'));
    printf("mien teste bon -- 9 ---->%d\n", ft_isdigit('9'));
    printf("mien teste bon -- 5 ---->%d\n", ft_isdigit('5'));
    printf("mien teste faux -- ; ---->%d\n", ft_isdigit(';'));

    printf("vrai teste bon -- 0 ---->%d\n", isdigit('0'));
    printf("vrai teste bon -- 9 ---->%d\n", isdigit('9'));
    printf("vrai teste bon -- 5 ---->%d\n", isdigit('5'));
    printf("vrai teste faux -- ; ---->%d\n", isdigit(';'));
}