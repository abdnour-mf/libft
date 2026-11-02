#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* #include <fcntl.h>
#include <stdio.h>
int main()   
{                                      // O_APPEND
	int fd = open("hello", O_RDWR | O_TRUNC | O_CREAT, 0644);
	close(fd);
	ft_putchar_fd('S',fd);
} */