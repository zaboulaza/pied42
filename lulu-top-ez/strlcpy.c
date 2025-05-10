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

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t src_len;

    i = 0;
    src_len = ft_strlen(src);

    if (size == 0)
    return (src_len);

    while (i < (size - 1) && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (src_len);

}

#include <stdio.h>
#include <string.h>

int main ()
{
    char dest[50];
    const char src[] = "je vais bruler la poste";
    printf("Nour test -- je vais bruler la poste ----> %ld\n", ft_strlcpy(dest, src, 7));
    printf("Vrai test -- je vais bruler la poste ----> %ld\n", strlcpy(dest, src, 7));
}