#include "libft.h"

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
    printf("%c\n", ft_toupper('a'));
    printf("%c\n", ft_toupper('P'));
    printf("%c\n", ft_toupper(']'));
    printf("%c\n", toupper('3'));
    printf("%c\n", toupper('-'));
    printf("%c\n", toupper(']'));
    printf("%c\n", toupper('-'));
    printf("%c\n", toupper('*'));
    printf("%c\n", toupper('P'));
    return 0;
} */