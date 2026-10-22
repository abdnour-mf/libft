#include "libft.h"
int count_digits(int n)
{
    int count;

    count = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        n *= -1;
        count++;
    }
    while (n >= 1)
    {
        n = n / 10;
        count++;
    }
    return (count);
}

char *ft_itoi(int n)
{
    char *num;

    num = malloc(count_digits(n) + 1);
    if (!num)
        return (NULL);

    return (num);
}

int main()
{
    printf("%d\n", count_digits(-999));
    printf("%d\n", count_digits(-99));
    printf("%d\n", count_digits(-10));
    printf("%d\n", count_digits(-9));
    printf("%d\n", count_digits(-1));
    return 0;
}