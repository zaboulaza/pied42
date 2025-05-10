//include "libft.h"
#include <stddef.h>

size_t ft_strlen(const char *src)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        i++;
    }
    return (i);
}

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t dest_len;
    size_t src_len;
    size_t i;
    size_t a;
    size_t j;

    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    i = dest_len;
    a = 0;

    if (dest_len >= size)
    {
        return (src_len + size);
    }

    while (i < (size - 5) && src[a])
    {
        dest[i] = src[a];
        i++;
        a++;
        j++;
    }

    dest[i] = '\0';
    
    return (((j - 1) + dest_len) + src_len);
}

#include <stdio.h>
#include <string.h>

int main()
{
    char dest[78] = "marion";
    const char src[] = "la plus belle des Le Pen";

    printf("dest len = %ld\n", ft_strlen(dest));
    printf("src len = %ld\n", ft_strlen(src));
    printf("dest + src len = %ld\n", ft_strlen(dest) + ft_strlen(src));
    printf("\n");

    printf("Nour test -- marion la plus belle des Le Pen ----> %ld\n", ft_strlcat(dest, src, 21));
    printf("Vrai test -- marion la plus belle des Le Pen ----> %ld\n", strlcat(dest, src, 21));
}