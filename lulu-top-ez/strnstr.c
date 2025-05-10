// include "libft.h"
#include <stddef.h>

char *ft_strnstr(const char *str1, const char *s2, size_t len)
{
    size_t i;
    size_t j;
    size_t start;
    size_t k;

    i = 0;
    j = 0;
    k = 0;

    if (s2[i] == '\0')
        return ((char *)str1);
    
    while (str1[i] && s2[j] && i < len)
    {
        j = 0;
        k = 0;

        if (str1[i] == s2[j])
        {
            start = i;

            while (str1[i + k] == s2[j] && i + k < len)
            {
                j++;
                k++;
                if (s2[j] == '\0')
                    return ((char *)(str1 + start));
            }
        }
        i++;
    }
    return (NULL);
    
}

#include <stdio.h>
#include <string.h>

int main()
{
    const char str1[] = "LOL non TFT oui";
    const char s2[] = "TFT";

    printf("Nour test -- TFT oui ----> %s\n", ft_strnstr(str1, s2, 13));
    //printf("Vrai test -- TFT oui ----> %s\n", strnstr(str1, s2, 13));
}