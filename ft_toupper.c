int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

/* #include <stdio.h>
int main()
{
    printf("%c", ft_toupper('a'));
    printf("%c", ft_toupper('g'));
    printf("%c", ft_toupper('z'));
    return 0;
} */