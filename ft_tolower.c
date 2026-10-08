int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

/* #include <stdio.h>
int main()
{
    printf("%c", ft_tolower('A'));
    printf("%c", ft_tolower('G'));
    printf("%c", ft_tolower('9'));
    return 0;
} */