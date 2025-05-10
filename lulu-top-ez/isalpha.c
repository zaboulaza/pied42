//#include "libft.h"

int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

#include <ctype.h>
#include <stdio.h>
int main()
{
    printf("mien teste bon -- A ---->%d\n", ft_isalpha('A'));
    printf("mien teste bon -- z ---->%d\n", ft_isalpha('z'));
    printf("mien teste bon -- v ---->%d\n", ft_isalpha('v'));
    printf("mien teste faux -- : ---->%d\n", ft_isalpha(':'));

    printf("vrai teste bon -- A ---->%d\n", isalpha('A'));
    printf("vrai teste bon -- z ---->%d\n", isalpha('z'));
    printf("vrai teste bon -- v ---->%d\n", isalpha('v'));
    printf("vrai teste faux -- : ---->%d\n", isalpha(':'));
}