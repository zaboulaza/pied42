// #include "libft.h"
#include <unistd.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putnbr_fd(int nb, int fd)
{
    if (nb == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb = -nb;
    }
    if (nb > 9)
    {
        ft_putnbr_fd(nb / 10, fd);
        ft_putnbr_fd(nb % 10, fd);
    }
    else
        ft_putchar_fd((nb + '0'), fd); 
}

int main()
{
    ft_putnbr_fd(-125, 1);
}