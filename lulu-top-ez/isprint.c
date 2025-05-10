//#include "libft.h"

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    else
        return (0);
}


#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("mien teste bon -- 32 ---->%d\n", ft_isprint(32));
    printf("mien teste faux -- 31 ---->%d\n", ft_isprint(31));
    printf("mien teste bon -- 126 ---->%d\n", ft_isprint(126));
    printf("mien teste faux -- 165 ---->%d\n", ft_isprint(165));

    printf("vrai teste bon -- 32 ---->%d\n", isprint(32));
    printf("vrai teste faux -- 31 ---->%d\n", isprint(31));
    printf("vrai teste bon -- 126 ---->%d\n", isprint(126));
    printf("vrai teste faux -- 127 ---->%d\n", isprint(127));
}