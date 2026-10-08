
void    ft_bzero(void *s, size_t n)
{
    char *p = (char *)s;
    size_t i = 0;
    while(i < n)
    {
        p[i] = 0;
        i++;
    }
}

// 2nd version
/* #include "libft.h"
void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
} */

/* #include <stdio.h>
int main()
{
    int i = 0;
    char buffer[5] = "hello";
    while(i < 5)   
    {
        printf("%d", buffer[i]);
        printf("\t");
        i++;
    }
    printf("\n");
    ft_bzero(buffer, 3);
    i = 0;
    while(i < 5)   
    {
        printf("%d", buffer[i]);
        printf("\t");
        i++;
    }
    return 0;
} */