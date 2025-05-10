// #include "libft.h"
#include <unistd.h>
#include <stddef.h>

void ft_putstr_fd(char *str, int fd)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
    
}

int main()
{
    ft_putstr_fd("Nourrrrr", 1);
}