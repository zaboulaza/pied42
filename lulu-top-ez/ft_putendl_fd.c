// #include "libft.h"
#include <unistd.h>
#include <stddef.h>

void ft_putendl_fd(char *s, int fd)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
    write(fd, "\n", 1);
}

int main()
{
    ft_putendl_fd("Nourrrrr", 1);
}