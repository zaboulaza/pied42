//#include "libft.h"

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    else
        return (0);
}


#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("mien teste bon -- 85 ---->%d\n", ft_isascii(85));
    printf("mien teste bon -- 9 ---->%d\n", ft_isascii(9));
    printf("mien teste bon -- 127 ---->%d\n", ft_isascii(127));
    printf("mien teste faux -- 165 ---->%d\n", ft_isascii(165));

    printf("vrai teste bon -- 85 ---->%d\n", isascii(85));
    printf("vrai teste bon -- 9 ---->%d\n", isascii(9));
    printf("vrai teste bon -- 127 ---->%d\n", isascii(127));
    printf("vrai teste faux -- 165 ---->%d\n", isascii(165));
}